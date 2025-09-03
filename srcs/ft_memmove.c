/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:20:34 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 12:20:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp;
	unsigned char	*src_str;
	unsigned char	*dest_str;

	src_str = (unsigned char *)src;
	dest_str = (unsigned char *)dest;
	temp = malloc(n);
	i = 0;
	while (i < n)
	{
		temp[i] = src_str[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_str[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest_str);
}

// int main(void) {
//     char data[] = "123456";

//     // Overlapping copy
//     ft_memmove(data + 2, data, 4);   
//     printf("ft_memmove:  %s\n", data);

//     char data2[] = "123456";
//     memmove(data2 + 2, data2, 4); 
//     printf("memmove: %s\n", data2);

//     return 0;
// }