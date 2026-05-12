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


t_config* extract_config()
{
    t_config *config;

    config = malloc(sizeof(t_config));

    config->number_of_coders = 4;
    config->time_to_burnout = 700;
    config->time_to_compile = 200;
    config->time_to_debug = 200;
    config->time_to_refactor = 200;
    config->number_of_compiles_required = 3;
    config->dongle_cooldown = 50;
    config->scheduler_type = "FIFO";

    return config;
}


t_dongle*	initialize_dongles(t_config* config)
{
	t_dongle	*dongles;
	int			i;

	dongles = malloc(sizeof(t_dongle) * config->number_of_coders);

	i = 0;
	while(i < config->number_of_coders)
	{
		dongles[i].scheduler = malloc(sizeof(t_heap));
		dongles[i].scheduler->requests = malloc(sizeof(t_request) * 2);
		dongles[i].scheduler->size = 0;
		dongles[i].scheduler->capacity = 2;

		dongles[i].available_at = 0;
		dongles[i].holder_id = -1;
		pthread_mutex_init(&dongles[i].mutex, NULL);
		pthread_cond_init(&dongles[i].cond, NULL);
		i++;
	}
	return dongles;
}


t_coder*	initialize_coders(t_dongle* dongles, t_config* config)
{
	int	i;
    t_coder		*coders;

    coders = malloc(sizeof(t_coder) * config->number_of_coders);

	i = 0;
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
		i++;
	}
	return coders;
}


void free_memory(t_config *config, t_dongle *dongles, t_coder *coders)
{
    int i;

    if (!config || !dongles || !coders)
        return;

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
    free(dongles);
    free(coders);
    free(config);
}


long	get_time_ms(void)
{
    t_val	tv;
	t_zone	tz;

	gettimeofday(&tv, &tz);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

void	swap_heap_items(t_request requests)
{
	
}



void	set_dongle_heap_by_fifo(t_coder *coder)
{
	if (coder->left_dongle->scheduler->size==0 || coder->left_dongle->scheduler->size==2)
	{
		coder->left_dongle->scheduler->requests[0].coder_id = coder->id;
		coder->left_dongle->scheduler->requests[0].priority_key = get_time_ms;
		coder->left_dongle->scheduler->size += 1;
	}
	else if (coder->left_dongle->scheduler->size==1)
	{
		coder->left_dongle->scheduler->requests[1].coder_id = coder->id;
		coder->left_dongle->scheduler->requests[1].priority_key = get_time_ms;
		coder->left_dongle->scheduler->size += 1;
	}
}



void*	run_the_routine(void *args)
{
	t_coder	*coder;

	coder = (t_coder *)args;
	if(!strcmp(coder->config->scheduler_type, "FIFO"))
		set_dongle_heap_by_fifo(coder);

	printf("coder: %d is running...\n", coder->id);
	printf("time: %ld\n", get_time_ms());
	return NULL;
}


int main()
{
	t_config	*config;
    t_dongle	*dongles;
    t_coder		*coders;
	pthread_t	*monitor;
    int i;
	(void)monitor;

    config = extract_config();
    dongles = initialize_dongles(config);
    coders = initialize_coders(dongles, config);

	i = 0;
	while (i < config->number_of_coders)
	{
		pthread_create(&coders[i].thread, NULL, run_the_routine, &coders[i]);
		i++;
	}
	sleep(1.2);
	i = 0;
	while (i < config->number_of_coders)
	{
		pthread_cancel(coders[i].thread);
		i++;
	}

	// printf("Main thread finished. Counts: %d\n", counter);
	free_memory(config, dongles, coders);
	return 0;
}
