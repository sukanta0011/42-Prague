/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:15:39 by sudas             #+#    #+#             */
/*   Updated: 2025/08/21 10:30:52 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	isspace_char(char c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int			neg_counter;
	int			i;
	long int	num_int;

	i = 0;
	neg_counter = 1;
	num_int = 0;
	while (str[i] != '\0' && isspace_char(str[i]))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg_counter = -neg_counter;
		i++;
	}
	if (!is_number(str[i]))
		return (0);
	while (str[i] != '\0' && is_number(str[i]))
	{
		num_int = num_int * 10 + (str[i] - '0');
		i++;
	}
	return (neg_counter * num_int);
}

// int	main(void)
// {
// 	char str[] = "       \t\n\f\r\v\n  -000000000000002331a3424 ";
// 	// int test_numer;
// 	int number1, number2;
// 	number1 = ft_atoi(str);
// 	printf("%d\n", number1);
// 	number2 = atoi(str);
// 	printf("%d", number2);

// 	// test_numer = 2147483647*10;
// 	// printf("%d\n", test_numer);
// }