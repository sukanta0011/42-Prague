/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedular.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:35:23 by sudas             #+#    #+#             */
/*   Updated: 2026/05/17 03:10:06 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


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


void	register_coder(t_coder *coder, long stored_time)
{
	long int	time_val;

	if (!coder->coding && !coder->debuging &&\
		!coder->refactoring && !coder->is_registered)
	{
		if (stored_time != -1)
			time_val = stored_time;
		else
		{
			time_val = get_time_ms() - coder->sim_start_time;
			// printf("schedular: %s, %d\n", coder->config->scheduler_type);
			if (!strcmp(coder->config->scheduler_type, "EDF"))
				time_val += coder->config->time_to_burnout;
		}
		// printf("coder: %d, time: %ld\n", coder->id, time_val);
		set_request_for_dongles(coder->left_dongle, coder->id, time_val);
		set_request_for_dongles(coder->right_dongle, coder->id, time_val);
		
		coder->is_registered = 1;

		// printf("dongle %d: %d, %d\n",coder->id, coder->left_dongle->scheduler->requests[0].coder_id, coder->left_dongle->scheduler->requests[1].coder_id);
		// printf("dongle %d: %d, %d\n",((coder->id + 1) % coder->config->number_of_coders), coder->right_dongle->scheduler->requests[0].coder_id, coder->right_dongle->scheduler->requests[1].coder_id);
		// printf("dongle %d: %ld, %ld\n",coder->id, coder->left_dongle->scheduler->requests[0].priority_key, coder->left_dongle->scheduler->requests[1].priority_key);
		// printf("dongle %d: %ld, %ld\n",coder->id + 1, coder->right_dongle->scheduler->requests[0].priority_key, coder->right_dongle->scheduler->requests[1].priority_key);
	}
}

void	register_all_coder(t_coder *coders)
{
	int	i;

	i = 0;
	while (i < coders[0].config->number_of_coders)
	{
		register_coder(&coders[i], -1);
		i++;
	}
}


void	backoff(t_coder *coder)
{
	int			left_top;
	int			right_top;
	long		time_val;
	
	left_top = coder->left_dongle->scheduler->requests[0].coder_id;
	right_top = coder->right_dongle->scheduler->requests[0].coder_id;
	if ((left_top == coder->id && right_top == coder->id) ||\
		(left_top != coder->id && right_top != coder->id))
		return ;
	if (left_top == coder->id && right_top != coder->id)
	{
		time_val = coder->left_dongle->scheduler->requests[0].priority_key;
		remove_request_for_dongles(coder->left_dongle);
		usleep(1000);
		set_request_for_dongles(coder->left_dongle, coder->id, time_val);

	}
	else if (left_top != coder->id && right_top == coder->id)
	{
		time_val = coder->right_dongle->scheduler->requests[0].priority_key;
		remove_request_for_dongles(coder->right_dongle);
		usleep(1000);
		set_request_for_dongles(coder->right_dongle, coder->id, time_val);
	}
}


void	*run_the_routine(void *args)
{
	t_coder		*coder;
	int			left_top;
	int			right_top;

	coder = (t_coder *)args;
	while (1)
	{
		if (coder->completed_compile == coder->config->number_of_compiles_required ||\
			*coder->stop_sim)
		{
			coder->completed = 1;
			return NULL;
		}
		register_coder(coder, -1);
		backoff(coder);
		left_top = coder->left_dongle->scheduler->requests[0].coder_id;
		right_top = coder->right_dongle->scheduler->requests[0].coder_id;
		if (left_top == coder->id && right_top == coder->id &&\
            !coder->coding && !coder->debuging &&\
			!coder->refactoring && coder->config->number_of_coders != 1)
		{
			coder->is_registered = 0;
			compile(coder);
			debug(coder);
			refactor(coder);
		}
        usleep(50);
	}
}
