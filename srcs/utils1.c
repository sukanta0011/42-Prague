/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:50:13 by sudas             #+#    #+#             */
/*   Updated: 2025/09/24 23:50:13 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	t_uint	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_putstr(char *str)
{
	t_uint	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_puterror(char *str)
{
	t_uint	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	pass_non_numbers(char *str, int *pos, int *sign)
{
	int	i;

	i = *pos;
	while (str[i] && ((str[i] >= '\t' && str[i] <= '\r')
			|| str[i] == ' '))
		i++;
	if (str[i] == '-' && str[i + 1])
	{
		(*sign) *= -1;
		i++;
	}
	else if (str[i] == '+' && str[i + 1])
		i++;
	*pos = i;
}

int	str_to_num(char *str, long int *num)
{
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	*num = 0;
	pass_non_numbers(str, &i, &sign);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			(*num) = (*num) * 10 + (str[i] - '0');
			i++;
		}
		else
			return (0);
	}
	(*num) = (*num) * sign;
	return (1);
}
