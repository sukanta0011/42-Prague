/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:38:24 by sudas             #+#    #+#             */
/*   Updated: 2026/05/16 19:38:24 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

t_dongle	*initialize_dongles(t_config* config)
{
	t_dongle	*dongles;
	int			i;

	dongles = malloc(sizeof(t_dongle) * config->number_of_coders);

	i = 0;
	while(i < config->number_of_coders)
	{
		dongles[i].scheduler = malloc(sizeof(t_heap));
		dongles[i].scheduler->requests = malloc(sizeof(t_request) * 2);
		dongles[i].scheduler->requests[0].coder_id = -1;
		dongles[i].scheduler->requests[1].coder_id = -1;
		dongles[i].scheduler->size = 0;
		dongles[i].scheduler->capacity = 2;
		dongles[i].available_at = 0;
		dongles[i].in_use = 0;
		pthread_mutex_init(&dongles[i].mutex, NULL);
		pthread_cond_init(&dongles[i].cond, NULL);
		i++;
	}
	return dongles;
}


t_coder		*initialize_coders(t_dongle* dongles, t_config* config, long int start_time)
{
	int		i;
    t_coder	*coders;
	t_mutex	*print_lock;
	int		*stop_sim;

    coders = malloc(sizeof(t_coder) * config->number_of_coders);
	print_lock = malloc(sizeof(t_mutex));
	stop_sim = malloc(sizeof(int));
	pthread_mutex_init(print_lock, NULL);

	i = 0;
	*stop_sim = 0;
	while(i < config->number_of_coders)
	{
		coders[i].id = i;
		coders[i].burnout_deadline = config->time_to_burnout;
		coders[i].left_dongle = &dongles[i];
		coders[i].right_dongle = &dongles[(i + 1) % config->number_of_coders];
		coders[i].config = config;
		coders[i].coding = 0;
		coders[i].debuging = 0;
		coders[i].refactoring = 0;
		coders[i].is_registered = 0;
        coders[i].completed_compile = 0;
		coders[i].completed = 0;
		coders[i].stop_sim = stop_sim;
		coders[i].sim_start_time = start_time;
		coders[i].print_lock = print_lock;
		i++;
	}
	return coders;
}
