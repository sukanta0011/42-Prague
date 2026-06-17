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

/*
* Function: ft_memcmp
* --------------------
*	Compare the letters between string-1 and string-2 
*	until their is a mismatch else until n byte is reached
*	and return the ASCII value difference of the mismatched
*	character else the n-th character.
*
*	s1 (const void *): address of first string.
*	s2 (const void *): address of second string.
*	n (size_t): number of bytes.
*
*	returns: the ASCII value difference of the mismatched
*	character and if there is no mismatch, then the n-th character.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	if (n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((i < n - 1) && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
