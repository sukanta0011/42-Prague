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

void	assign_val_to_coders(t_coder *coders, t_dongle *dongles,\
			t_config *config)
{
	int	i;

	i = 0;
	while (i < config->number_of_coders)
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
		i++;
	}
}

void	assign_other_val_to_coders(t_coder *coders,\
			int *stop_sim, long start_time,\
			t_mutex *print_lock)
{
	int	i;

	i = 0;
	pthread_mutex_init(print_lock, NULL);
	*stop_sim = 0;
	while (i < coders[0].config->number_of_coders)
	{
		coders[i].stop_sim = stop_sim;
		coders[i].sim_start_time = start_time;
		coders[i].print_lock = print_lock;
		i++;
	}
}

t_coder	*initialize_coders(t_dongle *dongles,\
			t_config *config, long start_time)
{
	t_coder	*coders;
	t_mutex	*print_lock;
	int		*stop_sim;

	print_lock = malloc(sizeof(t_mutex));
	if (!print_lock)
		return (NULL);
	coders = malloc(sizeof(t_coder) * config->number_of_coders);
	if (!print_lock)
	{
		free(print_lock);
		return (NULL);
	}
	stop_sim = malloc(sizeof(int));
	if (!stop_sim)
	{
		free(print_lock);
		free(coders);
		return (NULL);
	}
	assign_val_to_coders(coders, dongles, config);
	assign_other_val_to_coders(coders, stop_sim, start_time, print_lock);
	return (coders);
}
