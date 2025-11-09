/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:15:49 by sudas             #+#    #+#             */
/*   Updated: 2025/11/08 23:26:08 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strlcat
* --------------------
*	Concatenate the source string with the destination
*	until the (size - dest len - 1) if size > dest len
*	and use last byte for NULL termination as long
*	as size > 0. Size represent total bytes available.
*
*	dest (void *): memory address of the destination.
*	src (const void *): memory address of the source.
*	size (unsigned int): number of bytes to be copped.
*
*	returns: length of the destination + source string.
*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
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
