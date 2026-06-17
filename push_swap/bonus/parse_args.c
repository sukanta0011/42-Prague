/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:52:32 by sudas             #+#    #+#             */
/*   Updated: 2025/09/27 00:52:32 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_duplicate(t_dll_info *lst_info, long int *new_value)
{
	t_dbl_ll	*current;

	current = lst_info->head;
	while (current)
	{
		if (current->data == *new_value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	store_int(t_dll_info *lst_a, char *str, int *sign, int *pos)
{
	int			i;
	long int	num;

	i = *pos;
	num = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num = num * (*sign);
	*pos = i;
	if (!is_duplicate(lst_a, &num))
	{
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		add_at_back(lst_a, (int)num);
	}
	else
		return (0);
	return (1);
}

int	store_in_stack(int argc, char **argv, t_dll_info *lst_info)
{
	int			i;
	int			j;
	int			sign;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			sign = 1;
			skip_non_numbers(argv[i], &j, &sign);
			if (argv[i][j] <= '0' && argv[i][j] >= '9')
				return (0);
			if (argv[i][j] == '\0')
				break ;
			if (!store_int(lst_info, argv[i], &sign, &j))
				return (0);
			if (argv[i][j] && argv[i][j] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}
