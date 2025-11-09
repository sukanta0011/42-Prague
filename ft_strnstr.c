/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:05:41 by sudas             #+#    #+#             */
/*   Updated: 2025/11/09 00:49:02 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strnstr
* --------------------
*	Look for the first occurrence of substring (needle,
*	only look until len) in the main string (haystack).
*
*	haystack (const void *): address of main string.
*	needle (const void *): address of sub string.
*	len (size_t): length of substring upto which matchin is needed
*
*	returns: the address of the first occurrence of sub-string
*	with in main string. If sub-string is empty, it returns the
*	address of the main string. If no match found, returns NULL.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ndl_len;

	i = 0;
	ndl_len = ft_strlen((char *)needle);
	if (ndl_len == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (j < ndl_len && (j + i) < len && (haystack[i + j] == needle[j])
			&& haystack[j + i])
			j++;
		if (j == ndl_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
