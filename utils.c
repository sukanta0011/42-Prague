/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:38:39 by sudas             #+#    #+#             */
/*   Updated: 2026/05/17 00:48:05 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	swap_items(t_request *item1, t_request *item2)
{
	int temp_coder_id;
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
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}


long	get_max_value(long a, long b)
{
	if(a > b)
		return a;
	else
		return b;
}


void	print_message(t_coder* coder, char* msg)
{
	long time_since_sim_start;

	pthread_mutex_lock(coder->print_lock);
	time_since_sim_start = get_time_ms() - coder->sim_start_time;
	printf("%ld %d %s\n", time_since_sim_start, coder->id + 1, msg);
	pthread_mutex_unlock(coder->print_lock);
}