/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:40:57 by sudas             #+#    #+#             */
/*   Updated: 2026/05/20 13:24:28 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*stop_simulation(t_coder *coders, int coder_no)
{
	int	i;

	i = 0;
	pthread_mutex_lock(coders[coder_no].stop_sim_lock);
	*coders[coder_no].stop_sim = 1;
	pthread_mutex_unlock(coders[coder_no].stop_sim_lock);
	while (i < coders[0].config->number_of_coders)
	{
		pthread_mutex_lock(&coders[i].left_dongle->mutex);
		pthread_cond_broadcast(&coders[i].left_dongle->cond);
		pthread_mutex_unlock(&coders[i].left_dongle->mutex);
		i++;
	}
	print_message(&coders[coder_no], "burned out");
	return (NULL);
}

void	*monitor_coders(void *args)
{
	t_coder		*coders;
	long		now;
	int			i;
	int			burnout_deadline;

	coders = (t_coder *)args;
	while (1)
	{
		i = 0;
		now = get_time_ms() - coders[0].sim_start_time;
		while (i < coders[0].config->number_of_coders)
		{
			pthread_mutex_lock(coders[i].burnout_lock);
			burnout_deadline = coders[i].burnout_deadline;
			pthread_mutex_unlock(coders[i].burnout_lock);
			if (now >= burnout_deadline)
				return (stop_simulation(coders, i));
			if (coders[i].completed)
				return (NULL);
			i++;
		}
		usleep(100);
	}
}
