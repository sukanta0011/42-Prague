#include "codexion.h"


void	free_memory(t_config *config, t_dongle *dongles, t_coder *coders, t_mutex *print_lock)
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
	pthread_mutex_destroy(print_lock);
	free(print_lock);
    free(dongles);
    free(config);
    free(coders);
}
