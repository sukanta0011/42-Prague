/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:46:08 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 11:58:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
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
		if (src_str[i] == (unsigned char)c)
			return (&dest_str[i + 1]);
		i++;
	}
	return (NULL);
}

// int main(void) {
//     char src[] = "Hello World";
//     char dest1[20];
// 	char dest2[20];

//     memccpy(dest1, src, 'o', sizeof(src));
// 	printf("%s\n", dest1);
//     ft_memccpy(dest2, src, 'o', sizeof(src));
// 	printf("%s\n", dest2);
//     return 0;
// }