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

/*
* Function: ft_memcpy
* --------------------
*	copy n byte from source to destination
*
*	dest (void *): memory address of the destination
*	src (const void *): memory address of the source
*	n (size_t): number of bytes to be copped
*
*	returns: memory address of the destination
*/
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
