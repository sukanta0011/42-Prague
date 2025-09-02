/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:45:33 by sudas             #+#    #+#             */
/*   Updated: 2025/08/11 15:45:33 by sudas            ###   ########.fr       */
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

char	*ft_strupcase(char *str)
{
	int	i;
	int	validator;

	validator = 0;
	i = 0;
	while (str[i] != '\0')
	{
		validator = validate_char('a', 'z', str[i]);
		if (validator == 1)
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str[] = "aBCD3 4eF";
// 	char *return_str;

// 	return_str = ft_strupcase(str);
// 	printf("%s", return_str);
// }
