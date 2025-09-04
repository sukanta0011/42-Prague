/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:43:21 by sudas             #+#    #+#             */
/*   Updated: 2025/08/12 11:43:21 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i] || i >= (n - 1))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char str1[] = "ABCd";
// 	char str2[] = "ABCdds";
// 	int real_fun;
// 	int custom_fun;

// 	// status = ft_strcmp(str1, str2);
// 	// status = claculate_str_ascii_sum(str1);
// 	real_fun = strncmp(str1, str2, 5);
// 	custom_fun = ft_strncmp(str1, str2, 5);
// 	printf("%d, %d\n", real_fun, custom_fun);
// 	// printf("%d", (int)str1[0]);
// }
