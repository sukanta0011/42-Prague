/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:06:41 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 10:06:41 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding_char(char pad, t_uint len)
{
	t_uint	i;

	i = 0;
	while ((int)i < (int)len)
	{
		ft_putchar(pad);
		i++;
	}
}

void	ft_putstr_len(char *str, t_uint len)
{
	t_uint	i;

	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	char_in_str(char c, char *str)
{
	t_uint	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_uint	get_max_len(int a, int b, int c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else if (c >= b && c >= b)
		return (c);
	return (0);
}

t_uint	get_min_len(int a, int b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}
