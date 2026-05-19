/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:41:29 by sudas             #+#    #+#             */
/*   Updated: 2026/05/19 23:23:04 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	finished_compile(t_coder *coder)
{
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	print_message(coder, "has taken a dongle");
	print_message(coder, "has taken a dongle");
	print_message(coder, "is compiling");
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
	coder->left_dongle->in_use = 1;
	coder->right_dongle->in_use = 1;
	coder->coding = 1;
	usleep(coder->config->time_to_compile * 1000);
	coder->left_dongle->available_at = get_time_ms()
		+ coder->config->dongle_cooldown;
	coder->right_dongle->available_at = get_time_ms()
		+ coder->config->dongle_cooldown;
	coder->left_dongle->in_use = 0;
	coder->right_dongle->in_use = 0;
	coder->completed_compile += 1;
	coder->coding = 0;
	pthread_mutex_unlock(&coder->right_dongle->mutex);
	pthread_mutex_unlock(&coder->left_dongle->mutex);
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
	pthread_mutex_lock(&coder->left_dongle->mutex);
	pthread_mutex_lock(&coder->right_dongle->mutex);
	now = get_time_ms();
	wait_time = get_max_value(coder->left_dongle->available_at,
			coder->right_dongle->available_at);
	if (now < wait_time)
	{
		ts.tv_sec = wait_time / 1000;
		ts.tv_nsec = (wait_time % 1000) * 1000000;
		pthread_cond_timedwait(&coder->left_dongle->cond,
			&coder->left_dongle->mutex, &ts);
		pthread_cond_timedwait(&coder->right_dongle->cond,
			&coder->right_dongle->mutex, &ts);
	}
	if (*coder->stop_sim)
		return ;
	finished_compile(coder);
}

void	debug(t_coder *coder)
{
	if (*coder->stop_sim)
		return ;
	coder->debuging = 1;
	print_message(coder, "is debugging");
	usleep(coder->config->time_to_debug * 1000);
	coder->debuging = 0;
}

void	refactor(t_coder *coder)
{
	if (*coder->stop_sim)
		return ;
	coder->refactoring = 1;
	print_message(coder, "is refactoring");
	usleep(coder->config->time_to_refactor * 1000);
	coder->refactoring = 0;
	pthread_mutex_lock(coder->burnout_lock);
	coder->burnout_deadline += coder->config->time_to_compile
		+ coder->config->time_to_debug
		+ coder->config->time_to_refactor
		+ coder->config->time_to_burnout;
	pthread_mutex_unlock(coder->burnout_lock);
}
