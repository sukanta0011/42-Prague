/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:46:08 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 08:46:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_str;
	const unsigned char	*src_str;

	i = 0;
	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char str1[] = "Hello worlds";
// 	char str2[] = "Hello worlds";
// 	char dest1[] = "weqwreqwrqrq";
// 	char dest2[] = "gsgsgsgseeer";

// 	printf("%s\n", str1);
// 	memcpy(dest1, &str1[5], 4);
// 	printf("%s\n", dest1);

// 	printf("%s\n", str2);
// 	ft_memcpy(dest2, &str2[5], 4);
// 	printf("%s\n", dest2);
// }