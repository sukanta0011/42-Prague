/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:40:57 by sudas             #+#    #+#             */
/*   Updated: 2026/05/17 00:48:34 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"


void	*monitor_coders(void *args)
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
		while (i < coders[0].config->number_of_coders)
		{
			if (now >= coders[i].burnout_deadline)
			{
				print_message(&coders[i], "burned out");
				pthread_mutex_lock(coders[i].print_lock);
				*coders[i].stop_sim = 1;
				pthread_mutex_unlock(coders[i].print_lock);
				return NULL;
			}
			if (coders[i].completed)
				finished_coders++;
			if (finished_coders == coders[0].config->number_of_coders)
				return NULL;
			i++;
			usleep(20);
		}
	}
}
