/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:46:08 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 09:17:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	// char str1[] = "Hello worlds";
// 	char str2[] = "Hello worlds";

// 	// printf("%s\n", str1);
// 	// memset(&str1[5], 65, 2 * sizeof(char));
// 	// printf("%s\n", str1);

// 	printf("%s\n", str2);
// 	ft_memset(&str2[5], 65, 2 * sizeof(char));
// 	printf("%s\n", str2);
// }