/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:15:49 by sudas             #+#    #+#             */
/*   Updated: 2025/09/08 18:46:55 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	cal_str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	src_len;

	src_len = cal_str_len(src);
	dest_len = cal_str_len(dest);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - dest_len -1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	// char str1[10] = "ABCA";
// 	// char str2[7] = "123456";
// 	char dest[10] = "ABCA";
// 	char src[7] = "123456";
// 	unsigned int a, b;

// 	// a = strlcat(str1, str2, 7);
// 	// printf("%s\t%d\n", str1, a);
// 	b = ft_strlcat(dest, src, 10);
// 	printf("%s\t%d\n", dest, b);
// }
