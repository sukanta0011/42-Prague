/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   schedular_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:35:23 by sudas             #+#    #+#             */
/*   Updated: 2026/05/18 00:55:36 by sudas            ###   ########.fr       */
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

	if (!coder->coding && !coder->debuging
		&& !coder->refactoring && !coder->is_registered)
	{
		if (stored_time != -1)
			time_val = stored_time;
		else
		{
			time_val = get_time_ms() - coder->sim_start_time;
			if (!strcmp(coder->config->scheduler_type, "EDF"))
				time_val += coder->config->time_to_burnout;
		}
		set_request_for_dongles(coder->left_dongle, coder->id, time_val);
		set_request_for_dongles(coder->right_dongle, coder->id, time_val);
		coder->is_registered = 1;
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
