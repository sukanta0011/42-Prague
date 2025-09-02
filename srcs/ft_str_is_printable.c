/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:41:17 by sudas             #+#    #+#             */
/*   Updated: 2025/08/11 15:41:17 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

// 'validate_char' function receive the starting character as 'start'
// and ending character as 'end' and the the character as 'c'
// which need to be validated.
int	validate_char(char start, char end, char c)
{
	while (start <= end)
	{
		if (c == start)
			return (1);
		start++;
	}
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int	i;
	int	validator;

	validator = 0;
	i = 0;
	if (str[0] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		validator = validate_char(' ', '~', str[i]);
		if (validator == 0)
			return (validator);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char str[] = "!aBC4552\n x@0/DeF~";
// 	int status;

// 	status = ft_str_is_printable(str);
// 	printf("%d", status);
// }
