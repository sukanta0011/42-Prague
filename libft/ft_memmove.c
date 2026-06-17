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

/*
* Function: ft_memmove
* --------------------
*	Move n bytes from source to destination. Memory address
*	could be overlapping, memmove take cares of this by checking
*	the memory location of both source and destination.
*	If dest (address) > src (address), copy from left -> right.
*	If src (address) > dest (address), copy from right -> left.
*
*	dest (void *): memory address of the destination
*	src (const void *): memory address of the source
*	n (size_t): number of bytes to be copped
*
*	returns: memory address of the destination
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*src_str;
	unsigned char	*dest_str;

	src_str = (unsigned char *)src;
	dest_str = (unsigned char *)dest;
	if (dest_str < src_str)
	{
		i = 0;
		while (i < n)
		{
			dest_str[i] = src_str[i];
			i++;
		}
	}
	else if (src_str < dest_str)
	{
		i = n;
		while (i > 0)
		{
			dest_str[i - 1] = src_str[i - 1];
			i--;
		}
	}
	return (dest_str);
}
