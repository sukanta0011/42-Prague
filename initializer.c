#include "codexion.h"


t_config	*extract_config()
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

    coders = malloc(sizeof(t_coder) * config->number_of_coders);
	print_lock = malloc(sizeof(t_mutex));
	pthread_mutex_init(print_lock, NULL);

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
		coders[i].is_registered = 0;
		coders[i].sim_start_time = start_time;
		coders[i].print_lock = print_lock;
		i++;
	}
	return coders;
}
