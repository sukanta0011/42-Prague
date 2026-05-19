/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:02:16 by sudas             #+#    #+#             */
/*   Updated: 2026/05/11 19:02:16 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	start_the_threads(t_coder *coders, t_config *config, t_dongle *dongles)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	register_all_coder(coders);
	while (i < config->number_of_coders)
	{
		pthread_create(&coders[i].thread, NULL, run_the_routine, &coders[i]);
		usleep(100);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_coders, coders);
	i = 0;
	while (i < config->number_of_coders)
	{
		pthread_join(coders[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
	free_memory(config, dongles, coders, coders[0].print_lock);
	return (0);
}

int	main(int av, char **ac)
{
	t_config	*config;
	t_dongle	*dongles;
	t_coder		*coders;
	long		start_time;

	start_time = get_time_ms();
	config = parse_config(av, ac);
	if (!config)
		return (1);
	dongles = initialize_dongles(config);
	if (!dongles)
	{
		free(config);
		return (1);
	}
	coders = initialize_coders(dongles, config, start_time);
	if (!coders)
	{
		clean_dongles(config->number_of_coders, dongles);
		free(dongles);
		free(config);
		printf("Error: Memory allocation failed for coders\n");
		return (1);
	}
	return (start_the_threads(coders, config, dongles));
}
