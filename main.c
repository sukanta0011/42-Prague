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

int	main(void)
{
	t_config	*config;
	t_dongle	*dongles;
	t_coder		*coders;
	pthread_t	monitor;
	long		start_time;
	int			i;

	start_time = get_time_ms();
	config = extract_config();
	dongles = initialize_dongles(config);
	coders = initialize_coders(dongles, config, start_time);
	i = 0;
	register_all_coder(coders);
	while (i < config->number_of_coders)
	{
		pthread_create(&coders[i].thread, NULL, run_the_routine, &coders[i]);
		usleep(10);
		i++;
	}
	pthread_create(&monitor, NULL, monitor_coders, coders);
	i = 0;
	while (i < config->number_of_coders)
	{
		pthread_join(coders[i].thread, NULL);
		i++;
	}
	free_memory(config, dongles, coders, coders[0].print_lock);
	return (0);
}
