/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 19:38:55 by sudas             #+#    #+#             */
/*   Updated: 2026/05/18 00:06:52 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	print_error_msg(char *error_msg)
{
	printf("Error: %s\n", error_msg);
	return (1);
}

int	assign_int_val(int *config_val,\
	char *val, char *error_msg)
{
	if (atoi(val) == 0)
		return (print_error_msg(error_msg));
	*config_val = atoi(val);
	return (0);
}

int	assign_long_val(long int *config_val,\
	char *val, char *error_msg)
{
	if (atoi(val) == 0)
		return (print_error_msg(error_msg));
	*config_val = atoi(val);
	return (0);
}

int	assign_parsed_values(char **ac, t_config *config)
{
	char	**error_msgs;
	int		error;

	error = 0;
	error_msgs = get_error_msg();
	if (!error_msgs)
		return (1);
	error += assign_int_val(&config->number_of_coders, ac[1], error_msgs[1]);
	error += assign_long_val(&config->time_to_burnout, ac[2], error_msgs[2]);
	error += assign_int_val(&config->time_to_compile, ac[3], error_msgs[3]);
	error += assign_int_val(&config->time_to_debug, ac[4], error_msgs[4]);
	error += assign_int_val(&config->time_to_refactor, ac[5], error_msgs[5]);
	error += assign_int_val(&config->number_of_compiles_required,
			ac[6], error_msgs[6]);
	error += assign_int_val(&config->dongle_cooldown, ac[7], error_msgs[7]);
	if (strcmp(ac[8], "fifo") != 0 && strcmp(ac[8], "edf") != 0)
		error += print_error_msg(error_msgs[8]);
	else
		config->scheduler_type = ac[8];
	free(error_msgs);
	return (error);
}

t_config	*parse_config(int av, char **ac)
{
	t_config	*config;
	int			error;

	error = 0;
	if (av < 9)
	{
		printf("Error: Missing Arguments, Required 8 args.");
		return (NULL);
	}
	config = malloc(sizeof(t_config));
	if (config == NULL)
	{
		printf("Error: Configuration memory allocation failed.");
		return (NULL);
	}
	error = assign_parsed_values(ac, config);
	if (error)
	{
		free(config);
		return (NULL);
	}
	return (config);
}
