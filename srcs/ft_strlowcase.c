/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:47:39 by sudas             #+#    #+#             */
/*   Updated: 2025/08/11 15:47:39 by sudas            ###   ########.fr       */
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

char	*ft_strlowcase(char *str)
{
	int	i;
	int	validator;

	validator = 0;
	i = 0;
	while (str[i] != '\0')
	{
		validator = validate_char('A', 'Z', str[i]);
		if (validator == 1)
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str[] = "aBCDg5  33F";
// 	char *return_str;

// 	return_str = ft_strlowcase(str);
// 	printf("%s", return_str);

// }
