#ifndef CODEXION_H
# define CODEXION_H


# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>


typedef	pthread_mutex_t		t_mutex;
typedef	struct	timeval		t_val;
typedef	struct	timezone	t_zone;
typedef struct	timespec	t_space;


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


typedef struct s_request {
	int		coder_id;
	long	priority_key; // Either timestamp (FIFO) or deadline (EDF)
}				t_request;


typedef struct s_heap {
    t_request	*requests;
    int			size;
    int			capacity;
}				t_heap;


typedef struct s_dongle
{
	pthread_mutex_t mutex;
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
	int			coding;
	int			debuging;
	int			refactoring;
	int			is_registered;
	long int	sim_start_time;
	t_mutex		*print_lock;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_config	*config;
}				t_coder;


t_config	*extract_config();
t_dongle	*initialize_dongles(t_config* config);
t_coder		*initialize_coders(t_dongle* dongles, t_config* config, long int start_time);


void	free_memory(t_config *config, t_dongle *dongles, t_coder *coders, t_mutex print_lock);

#endif