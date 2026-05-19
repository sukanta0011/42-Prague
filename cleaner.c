/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:39:31 by sudas             #+#    #+#             */
/*   Updated: 2026/05/16 19:39:31 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	clean_dongles(int num, t_dongle *dongles)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&dongles[i].mutex);
		pthread_cond_destroy(&dongles[i].cond);
		if (dongles[i].scheduler)
		{
			free(dongles[i].scheduler->requests);
			free(dongles[i].scheduler);
		}
		i++;
	}
}

void	clean_coders_locks(int num, t_coder *coders)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(coders[i].burnout_lock);
		free(coders[i].burnout_lock);
		i++;
	}
}

void	free_memory(t_config *config, t_dongle *dongles,\
			t_coder *coders, t_mutex *print_lock)
{
	if (!config || !dongles || !coders || !print_lock)
		return ;
	clean_dongles(config->number_of_coders, dongles);
	clean_coders_locks(config->number_of_coders, coders);
	pthread_mutex_destroy(print_lock);
	pthread_mutex_destroy(coders[0].stop_sim_lock);
	free(print_lock);
	free(coders[0].stop_sim_lock);
	free(coders[0].stop_sim);
	free(dongles);
	free(config);
	free(coders);
}
