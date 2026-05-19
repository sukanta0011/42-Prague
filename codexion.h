/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:39:21 by sudas             #+#    #+#             */
/*   Updated: 2026/05/16 19:39:21 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define HEAP_SIZE 2

typedef pthread_mutex_t		t_mutex;
typedef struct timeval		t_val;
typedef struct timezone		t_zone;
typedef struct timespec		t_space;

typedef struct s_config
{
	int			number_of_coders;
	long int	time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			number_of_compiles_required;
	int			dongle_cooldown;
	char		*scheduler_type;
}				t_config;

typedef struct s_request
{
	int		coder_id;
	long	priority_key; // Either timestamp (FIFO) or deadline (EDF)
}				t_request;

typedef struct s_heap
{
	t_request	*requests;
	int			size;
	int			capacity;
}				t_heap;

typedef struct s_dongle
{
	pthread_mutex_t	mutex;
	pthread_cond_t	cond;
	long int		available_at;
	int				in_use;
	t_heap			*scheduler;
}				t_dongle;

typedef struct s_coder
{
	pthread_t	thread;
	int			id;
	int			burnout_deadline;
	t_mutex		*burnout_lock;
	int			coding;
	int			debuging;
	int			refactoring;
	int			is_registered;
	int			completed_compile;
	int			completed;
	int			*stop_sim;
	t_mutex		*stop_sim_lock;
	long int	sim_start_time;
	t_mutex		*print_lock;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_config	*config;
}				t_coder;

// parser.c
t_config	*parse_config(int av, char **ac);

// initializer.c
t_dongle	*initialize_dongles(t_config *config);
t_coder		*initialize_coders(t_dongle *dongles,\
				t_config *config, long int start_time);

// schedular_operations.c
void		set_request_for_dongles(t_dongle *dongle,\
				int id, long int time_val);
void		remove_request_for_dongles(t_dongle *dongle);
void		register_coder(t_coder *coder, long stored_time);
void		register_all_coder(t_coder *coders);

// schedular.c
void		*run_the_routine(void *args);

// cleaner.c
void		clean_dongles(int num, t_dongle *dongles);
void		clean_coders_locks(int num, t_coder *coders);
void		free_memory(t_config *config,\
				t_dongle *dongles, t_coder *coders,\
				t_mutex *print_lock);

// heap_positions.c
int			parent(int index);
int			left_child(int index);
int			right_child(int index);

// heap_operations.c
void		move_up(int index, t_request *list);
void		move_down(int index, int size, t_request *list);
void		push(int coder_id, long priority_key, t_heap *heap);
void		pop(t_heap *heap);

// coder_routines.c
void		compile(t_coder *coder);
void		debug(t_coder *coder);
void		refactor(t_coder *coder);

// monitor.c
void		*monitor_coders(void *args);

// utils.c
void		swap_items(t_request *item1, t_request *item2);
long		get_time_ms(void);
long		get_max_value(long a, long b);
void		print_message(t_coder *coder, char *msg);
char		**get_error_msg(void);

#endif