/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:29:17 by sudas             #+#    #+#             */
/*   Updated: 2025/08/11 15:29:17 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	validate_char(char start, char end, char c)
{
	while (start <= end)
	{
		if (c == start || c == start + 32)
			return (1);
		start++;
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
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
		validator = validate_char('A', 'Z', str[i]);
		if (validator == 0)
			return (validator);
		i++;
	}
	return (1);
}

// int	main(void)
// {
// 	char str[] = "AellLg ";
// 	int status;

// 	status = ft_str_is_alpha(str);
// 	printf("%d", status);
// }
