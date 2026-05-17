/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:38:39 by sudas             #+#    #+#             */
/*   Updated: 2026/05/17 23:48:39 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	swap_items(t_request *item1, t_request *item2)
{
	int	temp_coder_id;
	int	temp_priority_key;

	temp_coder_id = item1->coder_id;
	temp_priority_key = item1->priority_key;
	item1->coder_id = item2->coder_id;
	item1->priority_key = item2->priority_key;
	item2->coder_id = temp_coder_id;
	item2->priority_key = temp_priority_key;
}

long	get_time_ms(void)
{
	t_val	tv;
	t_zone	tz;

	gettimeofday(&tv, &tz);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	get_max_value(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	print_message(t_coder *coder, char *msg)
{
	long	time_since_sim_start;

	pthread_mutex_lock(coder->print_lock);
	time_since_sim_start = get_time_ms() - coder->sim_start_time;
	printf("%ld %d %s\n", time_since_sim_start, coder->id + 1, msg);
	pthread_mutex_unlock(coder->print_lock);
}

char	**get_error_msg(void)
{
	char	**error_messages;

	error_messages = malloc(sizeof(char *) * 9);
	if (!error_messages)
	{
		printf("Error: Memory allocation for error messages failed");
		return (NULL);
	}
	error_messages[0] = "Usage error.";
	error_messages[1] = "Number of CODERS must be positive integer.";
	error_messages[2] = "Time to BURNOUT has to be positive ms.";
	error_messages[3] = "Time to COMPILE has to be positive ms.";
	error_messages[4] = "Time to DEBUG has to be positive ms.";
	error_messages[5] = "Time to REFACTOR has to be positive ms.";
	error_messages[6] = "Number of COMPILATION must be positive integer.";
	error_messages[7] = "Dongle to COOLDOWN time has to be positive ms.";
	error_messages[8] = "Invalid Schedular. Valid types are 'fifo' and 'edf'";
	return (error_messages);
}
