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
	if (dongle->scheduler->size==0)
	{
		dongle->scheduler->requests[0].coder_id = id;
		dongle->scheduler->requests[0].priority_key = time_val;
		dongle->scheduler->size += 1;
	}
	else if (dongle->scheduler->size==1)
	{
		dongle->scheduler->requests[1].coder_id = id;
		dongle->scheduler->requests[1].priority_key = time_val;
		dongle->scheduler->size += 1;
		if(dongle->scheduler->requests[0].priority_key >\
			dongle->scheduler->requests[1].priority_key)
		{
			swap_heap_items(dongle->scheduler->requests);
		}
	}
	else if (dongle->scheduler->size==2)
	{
		dongle->scheduler->requests[0].coder_id = id;
		dongle->scheduler->requests[0].priority_key = time_val;
		if(dongle->scheduler->requests[0].priority_key >\
			dongle->scheduler->requests[1].priority_key)
		{
			swap_heap_items(dongle->scheduler->requests);
		}
	}
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
	print_message(coder, "has taken a dongle");
	print_message(coder, "has taken a dongle");
	coder->coding = 1;
	print_message(coder, "is compiling");
	usleep(coder->config->time_to_compile);
	coder->left_dongle->available_at = get_time_ms() + coder->config->dongle_cooldown;
	coder->right_dongle->available_at = get_time_ms() + coder->config->dongle_cooldown;
	coder->left_dongle->in_use = 0;
	coder->right_dongle->in_use = 0;
	coder->coding = 0;
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
}


void coder_debug(t_coder *coder)
{
	coder->debuging = 1;
	print_message(coder, "is debugging");
	usleep(coder->config->time_to_debug);
	coder->debuging = 0;
}

void coder_refactor(t_coder *coder)
{
	coder->debuging = 1;
	print_message(coder, "is refactoring");
	usleep(coder->config->time_to_refactor);
	coder->debuging = 0;
}


void*	run_the_routine(void *args)
{
	t_coder		*coder;
	long int	time_val;

	coder = (t_coder *)args;
	while(1)
	{
		if(!coder->coding && !coder->debuging && !coder->refactoring && !coder->is_registered)
		{
			time_val = get_time_ms();
			if(!strcmp(coder->config->scheduler_type, "EDF"))
				time_val += coder->config->time_to_burnout;
			set_request_for_dongles(coder->left_dongle, coder->id, time_val);
			set_request_for_dongles(coder->right_dongle, coder->id, time_val);
			coder->is_registered = 1;
		}
		if((coder->left_dongle->scheduler->requests[0].coder_id == coder->id) &&\
			(coder->right_dongle->scheduler->requests[0].coder_id == coder->id))
		{
			coder->is_registered = 0;
			coder->left_dongle->scheduler->requests[0].coder_id = -1;
			coder->right_dongle->scheduler->requests[1].coder_id = -1;
			// coder_compile(coder);
			// coder_debug(coder);
			// coder_refactor(coder);
		}
	}
	return NULL;
}


int main()
{
	t_config	*config;
    t_dongle	*dongles;
    t_coder		*coders;
	long int	start_time;
    int i;

	start_time = get_time_ms();
	config = extract_config();
    dongles = initialize_dongles(config);
    coders = initialize_coders(dongles, config, start_time);

	i = 0;
	while (i < config->number_of_coders)
	{
		printf("Coder: %d starting...\n", i);
		pthread_create(&coders[i].thread, NULL, run_the_routine, &coders[i]);
		i++;
	}
	sleep(1.2);
	i = 0;
	while (i < config->number_of_coders)
	{
		pthread_cancel(coders[i].thread);
		i++;
	}

	// printf("Main thread finished. Counts: %d\n", counter);
	free_memory(config, dongles, coders, &coders[0].print_lock);
	return 0;
}
