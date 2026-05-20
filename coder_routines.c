/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:41:29 by sudas             #+#    #+#             */
/*   Updated: 2026/05/20 14:39:19 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	finished_compile(t_coder *coder)
{
	unlock_both_dongles(coder);
	print_message(coder, "has taken a dongle");
	print_message(coder, "has taken a dongle");
	print_message(coder, "is compiling");
	lock_both_dongles(coder);
	coder->left_dongle->in_use = 1;
	coder->right_dongle->in_use = 1;
	coder->coding = 1;
	precise_sleep(coder, coder->config->time_to_compile);
	coder->left_dongle->available_at = get_time_ms()
		+ coder->config->dongle_cooldown;
	coder->right_dongle->available_at = get_time_ms()
		+ coder->config->dongle_cooldown;
	coder->left_dongle->in_use = 0;
	coder->right_dongle->in_use = 0;
	coder->completed_compile += 1;
	coder->coding = 0;
	unlock_both_dongles(coder);
	remove_request_for_dongles(coder->right_dongle);
	remove_request_for_dongles(coder->left_dongle);
}

void	compile(t_coder *coder)
{
	long	now;
	long	wait_time;
	t_space	ts;

	if (*coder->stop_sim)
		return ;
	lock_both_dongles(coder);
	now = get_time_ms();
	wait_time = get_max_value(coder->left_dongle->available_at,
			coder->right_dongle->available_at);
	if (now < wait_time)
	{
		pthread_mutex_unlock(&coder->right_dongle->mutex);
		ts.tv_sec = wait_time / 1000;
		ts.tv_nsec = (wait_time % 1000) * 1000000;
		pthread_cond_timedwait(&coder->left_dongle->cond,
			&coder->left_dongle->mutex, &ts);
		pthread_mutex_lock(&coder->right_dongle->mutex);
	}
	if (*coder->stop_sim)
	{
		unlock_both_dongles(coder);
		return ;
	}
	finished_compile(coder);
}

void	debug(t_coder *coder)
{
	if (*coder->stop_sim)
		return ;
	coder->debuging = 1;
	print_message(coder, "is debugging");
	precise_sleep(coder, coder->config->time_to_debug);
	coder->debuging = 0;
}

void	refactor(t_coder *coder)
{
	if (*coder->stop_sim)
		return ;
	coder->refactoring = 1;
	print_message(coder, "is refactoring");
	precise_sleep(coder, coder->config->time_to_refactor);
	coder->refactoring = 0;
	pthread_mutex_lock(coder->burnout_lock);
	coder->burnout_deadline += coder->config->time_to_compile
		+ coder->config->time_to_debug
		+ coder->config->time_to_refactor
		+ coder->config->time_to_burnout;
	pthread_mutex_unlock(coder->burnout_lock);
}
