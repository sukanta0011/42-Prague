/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:43:21 by sudas             #+#    #+#             */
/*   Updated: 2025/08/12 11:43:21 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_memcmp
* --------------------
*	Compare the letters between string-1 and string-2 
*	until their is a mismatch else until n-th byte or
*	end of string 1 or string 2 is reached and return the
*	ASCII value difference of the mismatched character
*	else the n-th character.
*
*	s1 (char *): address of first string.
*	s2 (char *): address of second string.
*	n (size_t): number of bytes.
*
*	returns: the ASCII value difference of the mismatched
*	character and if there is no mismatch, then the n-th character.
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < n - 1))
		i++;
	return (s1[i] - s2[i]);
}
