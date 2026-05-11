#ifndef CODEXION_H
# define CODEXION_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mutex;

typedef struct s_config
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
}			t_config;


typedef struct s_dongle
{
	pthread_mutex_t mutex;
	pthread_cond_t	cond;
	long int		available_at;
	int				in_use;
}				t_dongle;


typedef struct s_coder
{
	pthread_t	thread;
	int			id;
	int			burnout_deadline;
	int			coding;
	int			debuging;
	int			refactoring;
	int			resting;
	t_dongle	*left_dongle;
	t_dongle	*right_dongle;
	t_config	*config;
}			t_coder;

#endif