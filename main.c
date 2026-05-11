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

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "codexion.h"


t_config* extract_config()
{
    t_config *config;

    config = malloc(sizeof(t_config));

    config->number_of_coders = 3;
    config->time_to_burnout = 700;
    config->time_to_compile = 200;
    config->time_to_debug = 200;
    config->time_to_refactor = 200;
    config->number_of_compiles_required = 3;
    config->dongle_cooldown = 50;
    config->scheduler_type = "FIFO";

    return &config;
}


int main()
{
	t_config *config;
    t_dongle *dongles;
    t_coder *coders;
    int i;

    config = extract_config();
    dongles = malloc(sizeof(t_dongle) * config->number_of_coders);
    coders = malloc(sizeof(t_coder) * config->number_of_coders);

	i = 0;
	while (i < config->number_of_coders)
	{
		coders[i]->id = i;
		coders[i].deadline = time_to_burnout;
		pthread_create(&coders[i].thread, NULL, thread_runner, &coders[i].id);
		i++;
	}
	sleep(1.2);
	i = 0;
	while (i < number_of_coders)
	{
		pthread_cancel(coders[i].thread);
		i++;
	}

	printf("Main thread finished. Counts: %d\n", counter);
	return 0;
}
