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

void	free_memory(t_config *config, t_dongle *dongles,\
			t_coder *coders, t_mutex *print_lock)
{
	int	i;

	if (!config || !dongles || !coders || !print_lock)
		return ;
	i = 0;
	while (i < config->number_of_coders)
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
	pthread_mutex_destroy(print_lock);
	free(print_lock);
	free(coders[0].stop_sim);
	free(dongles);
	free(config);
	free(coders);
}
