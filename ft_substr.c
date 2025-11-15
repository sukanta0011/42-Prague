/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:48:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 22:48:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strstr
* --------------------
*	Allocates memory and returns a substring from the string.
*	The substring starts at index ’start’ and has a maximum
*	length of ’len’.
*
*	s (char const *): memory address of main string
*	start (unsigned int): index of the string position from where
*						copying should start.
*	len (size_t): maximum length of the substring starting from the index.
*
*	returns: address of the new memory block with copied string.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen((char *)s);
	if (start >= str_len)
		len = 0;
	else if ((str_len - start) < len)
		len = (str_len - start);
	sub_str = malloc(sizeof(char) * (len + 1));
	if (!sub_str)
		return (NULL);
	if (start >= str_len)
	{
		sub_str[i] = '\0';
		return (sub_str);
	}
	while (s[start + i] && (i < len))
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
