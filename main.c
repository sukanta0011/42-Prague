#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "codexion.h"

int counter = 0;
t_mutex lock;


int main()
{
	int number_of_coders = 10000;
	int time_to_burnout = 50;
	// int time_to_compile = 50;
	// int time_to_debug = 50;
	// int time_to_refactor = 50;
	// int number_of_compiles_required = 50;
	// int dongle_cooldown = 50;
	// char *scheduler;
	t_coder coders[number_of_coders];
	t_mutex dongles[number_of_coders];
	int i;

	i = 0;
	while (i < number_of_coders)
	{
		coders[i].coder_no = i;
		coders[i].deadline = time_to_burnout;
		pthread_create(&coders[i].thread, NULL, thread_runner, &coders[i].coder_no);
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
