/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:37:25 by sudas             #+#    #+#             */
/*   Updated: 2025/08/12 11:37:25 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	cal_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_min_len(int a, int b)
{
	if (a >= b)
		return (a);
	else if (a < b)
		return (b);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i <= get_min_len(cal_str_len(s1), cal_str_len(s2)))
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char str1[] = "ABCDj";
// 	char str2[] = "ABCDI";
// 	int real_fun;
// 	int custom_fun;

// 	// status = ft_strcmp(str1, str2);
// 	// status = claculate_str_ascii_sum(str1);
// 	real_fun = strcmp(str1, str2);
// 	custom_fun = ft_strcmp(str1, str2);
// 	printf("%d, %d\n", real_fun, custom_fun);
// 	// printf("%d", (int)str1[0]);
// }
