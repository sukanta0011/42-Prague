/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:02:16 by sudas             #+#    #+#             */
/*   Updated: 2026/05/11 19:02:16 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


long	get_time_ms(void)
{
    t_val	tv;
	t_zone	tz;

	gettimeofday(&tv, &tz);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}


void	swap_heap_items(t_request *request)
{
	int temp_coder_id;
	int	temp_priority_key;

	temp_coder_id = request[0].coder_id;
	temp_priority_key = request[0].priority_key;
	request[0].coder_id = request[1].coder_id;
	request[0].priority_key = request[1].priority_key;
	request[1].coder_id = temp_coder_id;
	request[1].priority_key = temp_priority_key;	
}


void	set_request_for_dongles(t_dongle *dongle, int id, long int time_val)
{
	pthread_mutex_lock(&dongle->mutex);
	push(id, time_val, dongle->scheduler);
	pthread_mutex_unlock(&dongle->mutex);
}

void	remove_request_for_dongles(t_dongle *dongle)
{
	pthread_mutex_lock(&dongle->mutex);
	pop(dongle->scheduler);
	pthread_mutex_unlock(&dongle->mutex);
}


long	get_max_value(long a, long b)
{
	if(a > b)
		return a;
	else
		return b;
}


void	print_message(t_coder* coder, char* msg)
{
	long time_since_sim_start;

	pthread_mutex_lock(coder->print_lock);
	time_since_sim_start = get_time_ms() - coder->sim_start_time;
	printf("%ld %d %s", time_since_sim_start, coder->id, msg);
	pthread_mutex_unlock(coder->print_lock);
}


void	coder_compile(t_coder *coder)
{
	long	now;
	long	wait_time;
	t_space	ts;

	pthread_mutex_lock(&coder->left_dongle->mutex);
	pthread_mutex_lock(&coder->right_dongle->mutex);

	now = get_time_ms();
	wait_time = get_max_value(coder->left_dongle->available_at,\
		coder->right_dongle->available_at);
	if (now < wait_time)
	{
		ts.tv_sec = wait_time / 1000;
		ts.tv_nsec = (wait_time % 1000) * 1000000;
		pthread_cond_timedwait(&coder->left_dongle->cond, &coder->left_dongle->mutex, &ts);
		pthread_cond_timedwait(&coder->right_dongle->cond, &coder->right_dongle->mutex, &ts);
	}
	coder->left_dongle->in_use = 1;
	coder->right_dongle->in_use = 1;
	print_message(coder, "has taken a dongle\n");
	print_message(coder, "has taken a dongle\n");

	// coder->burnout_deadline += coder->config->time_to_compile + coder->config->time_to_debug + coder->config->time_to_refactor + coder->config->time_to_burnout;
	// printf("Burnout deadline of %d: %d\n", coder->id, coder->burnout_deadline);

	coder->coding = 1;

	print_message(coder, "is compiling\n");
	usleep(coder->config->time_to_compile * 1000);

	coder->left_dongle->available_at = get_time_ms() + coder->config->dongle_cooldown;
	coder->right_dongle->available_at = get_time_ms() + coder->config->dongle_cooldown;

	coder->left_dongle->in_use = 0;
	coder->right_dongle->in_use = 0;
    coder->completed_compile += 1;

	coder->coding = 0;
    // print_message(coder, "has released a dongle\n");
	// print_message(coder, "has released a dongle\n");

	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	remove_request_for_dongles(coder->right_dongle);
	remove_request_for_dongles(coder->left_dongle);
}


void coder_debug(t_coder *coder)
{
	coder->debuging = 1;
	print_message(coder, "is debugging\n");
	usleep(coder->config->time_to_debug * 1000);
	coder->debuging = 0;
}


void coder_refactor(t_coder *coder)
{
	coder->debuging = 1;
	print_message(coder, "is refactoring\n");
	usleep(coder->config->time_to_refactor * 1000);
	coder->debuging = 0;
}


void*	run_the_routine(void *args)
{
	t_coder		*coder;
	long int	time_val;

	coder = (t_coder *)args;
	while(1)
	{
		if(coder->completed_compile == coder->config->number_of_compiles_required)
			coder->stop_sim = 1;
		if(coder->stop_sim)
        {
            print_message(coder, "Completed all compiles\n");
            break;
        }
        if(!coder->coding && !coder->debuging && !coder->refactoring && !coder->is_registered)
		{
			time_val = get_time_ms();
			if(!strcmp(coder->config->scheduler_type, "EDF"))
				time_val += coder->config->time_to_burnout;
			// printf("coder: %d, time: %ld\n", coder->id, time_val);
			set_request_for_dongles(coder->left_dongle, coder->id, time_val);
			set_request_for_dongles(coder->right_dongle, coder->id, time_val);
			coder->is_registered = 1;
		}
		if((coder->left_dongle->scheduler->requests[0].coder_id == coder->id) &&\
			(coder->right_dongle->scheduler->requests[0].coder_id == coder->id &&\
            !coder->coding && !coder->debuging && !coder->refactoring))
		{
			coder->is_registered = 0;
			coder_compile(coder);
			coder_debug(coder);
			coder_refactor(coder);
		}
        usleep(50);
	}
	return NULL;
}

void	stop_simulation(t_coder *coders)
{
	int	i;

	i = 0;
	while (i < coders[0].config->number_of_coders)
	{
		coders[i].stop_sim = 1;
		i++;
	}
	
}

void*	monitor_coders(void *args)
{
	t_coder		*coders;
	long		now;
	int			i;
	int			finished_coders;

	coders = (t_coder *)args;
	finished_coders = 0;
	while(1)
	{
		i = 0;
		now = get_time_ms() - coders[0].sim_start_time;
		while(i < coders[0].config->number_of_coders)
		{
			if ((now) >= coders[i].burnout_deadline)
			{
				printf("now: %ld, burnout time: %d, coder: %d\n", now, coders[i].burnout_deadline, coders[i].id);
				print_message(&coders[i], "is burned out.\n");
				stop_simulation(coders);
				return NULL;
			}
			if (coders[i].stop_sim)
				finished_coders++;
			if (finished_coders == coders[0].config->number_of_coders)
				return NULL;
			i++;
			usleep(100);
		}
	}
	

}

int main()
{
	t_config	*config;
    t_dongle	*dongles;
    t_coder		*coders;
	pthread_t	monitor;

	long int	start_time;
    int i;

	start_time = get_time_ms();
	config = extract_config();
    dongles = initialize_dongles(config);
    coders = initialize_coders(dongles, config, start_time);

	i = 0;
	while (i < config->number_of_coders)
	{
		pthread_create(&coders[i].thread, NULL, run_the_routine, &coders[i]);
		usleep(50);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_coders, coders);
	
	i = 0;
	while (i < config->number_of_coders)
	{
        pthread_join(coders[i].thread, NULL);
		i++;
	}

	// printf("Main thread finished. Counts: %d\n", counter);
	free_memory(config, dongles, coders, coders[0].print_lock);
	return 0;
}
