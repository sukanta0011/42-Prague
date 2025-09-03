/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:05:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 12:05:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

// int main(void)
// {
// 	char s1[] = "hello world";
// 	char s2[] = "hello world";

// 	printf("%d\n", memcmp(&s1[1], &s2[2], 10));
// 	printf("%d\n", ft_memcmp(&s1[1], &s2[2], 10));
// }