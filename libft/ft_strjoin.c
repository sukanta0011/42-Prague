/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:04:28 by sudas             #+#    #+#             */
/*   Updated: 2025/09/03 23:04:28 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strlcat
* --------------------
*	Join string-1 and string-2 in a new memory and 
*	return the memory addrress.
*
*	s1 (char const *): memory address of string 1.
*	s2 (char const *): memory address of string 2.
*
*	returns: the memory address of the joined string.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*merged_str;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	merged_str = malloc(sizeof(char) * (s1_len + s2_len +1));
	if (!merged_str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		merged_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		merged_str[s1_len + i] = s2[i];
		i++;
	}
	merged_str[s1_len + i] = '\0';
	return (merged_str);
}
