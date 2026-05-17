/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_dongles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:38:24 by sudas             #+#    #+#             */
/*   Updated: 2026/05/17 23:18:17 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	heap_allocation(t_dongle *dongle, int dongle_no)
{
	int	error;

	error = 0;
	dongle->scheduler = malloc(sizeof(t_heap));
	if (!dongle->scheduler)
	{
		printf("Error: Schedular memory allocation \
			failed. Dongle %d.\n", dongle_no);
		error = 1;
	}
	dongle->scheduler->requests = malloc(sizeof(t_request) * 2);
	if (!dongle->scheduler->requests)
	{
		printf("Error: Heap memory allocation failed. Dongle %d.\n", dongle_no);
		error = 2;
	}
	return (error);
}

void	*initialize_heap(t_config *config, t_dongle *dongles)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < config->number_of_coders)
	{
		error = heap_allocation(&dongles[i], i);
		if (error)
		{
			clean_dongles(i, dongles, error);
			return (NULL);
		}
		dongles[i].scheduler->requests[0].coder_id = -1;
		dongles[i].scheduler->requests[1].coder_id = -1;
		pthread_mutex_init(&dongles[i].mutex, NULL);
		pthread_cond_init(&dongles[i].cond, NULL);
		i++;
	}
	return (dongles);
}

t_dongle	*initialize_dongles(t_config *config)
{
	t_dongle	*dongles;
	int			i;

	dongles = malloc(sizeof(t_dongle) * config->number_of_coders);
	if (!dongles)
	{
		printf("Error: Dongle memory allocation failed.");
		return (NULL);
	}
	if (!initialize_heap(config, dongles))
		return (NULL);
	i = 0;
	while (i < config->number_of_coders)
	{
		dongles[i].scheduler->size = 0;
		dongles[i].scheduler->capacity = 2;
		dongles[i].available_at = 0;
		dongles[i].in_use = 0;
		i++;
	}
	return (dongles);
}
