/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 11:35:38 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 11:35:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_memchr
* --------------------
*	Return the address of the first occurrence of the
*	provided character in the source string with in the first 
*	n bytes. If character does not exists, it return NULL.
*
*	s (const char *): starting address of the string.
*	c (int): character need to be checked in the n bytes.
*	n (size_t): number of bytes.
*
*	returns: the addrress of the first occurrence of
*	the character within the first n bytes else NULL.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
