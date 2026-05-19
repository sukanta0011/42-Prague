/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedular.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:35:23 by sudas             #+#    #+#             */
/*   Updated: 2026/05/19 10:17:59 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	backoff(t_coder *coder)
{
	int			left_top;
	int			right_top;
	long		time_val;

	pthread_mutex_lock(&coder->left_dongle->mutex);
	left_top = coder->left_dongle->scheduler->requests[0].coder_id;
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	pthread_mutex_lock(&coder->right_dongle->mutex);
	right_top = coder->right_dongle->scheduler->requests[0].coder_id;
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	if ((left_top == coder->id && right_top == coder->id)
		|| (left_top != coder->id && right_top != coder->id))
		return ;
	if (left_top == coder->id && right_top != coder->id)
	{
		pthread_mutex_lock(&coder->left_dongle->mutex);
		time_val = coder->left_dongle->scheduler->requests[0].priority_key;
		pthread_mutex_unlock(&coder->left_dongle->mutex);
		remove_request_for_dongles(coder->left_dongle);
		usleep(500);
		set_request_for_dongles(coder->left_dongle, coder->id, time_val);
	}
	else if (left_top != coder->id && right_top == coder->id)
	{
		pthread_mutex_lock(&coder->right_dongle->mutex);
		time_val = coder->right_dongle->scheduler->requests[0].priority_key;
		pthread_mutex_unlock(&coder->right_dongle->mutex);
		remove_request_for_dongles(coder->right_dongle);
		usleep(500);
		set_request_for_dongles(coder->right_dongle, coder->id, time_val);
	}
}

void	continue_routine(t_coder *coder)
{
	int	left_top;
	int	right_top;

	pthread_mutex_lock(&coder->left_dongle->mutex);
	left_top = coder->left_dongle->scheduler->requests[0].coder_id;
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	pthread_mutex_lock(&coder->right_dongle->mutex);
	right_top = coder->right_dongle->scheduler->requests[0].coder_id;
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	if (left_top == coder->id && right_top == coder->id
		&& !coder->coding && !coder->debuging
		&& !coder->refactoring && coder->config->number_of_coders != 1)
	{
		coder->is_registered = 0;
		compile(coder);
		debug(coder);
		refactor(coder);
	}
}

void	*run_the_routine(void *args)
{
	t_coder		*coder;

	coder = (t_coder *)args;
	while (1)
	{
		if (coder->completed_compile
			== coder->config->number_of_compiles_required
			|| *coder->stop_sim)
		{
			coder->completed = 1;
			return (NULL);
		}
		register_coder(coder, -1);
		backoff(coder);
		continue_routine(coder);
		usleep(50);
	}
}
