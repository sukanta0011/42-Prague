/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:10:20 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 19:10:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strrchar
* --------------------
*	Return the address of the first occurrence of the
*	provided character in the source string in reverse
*	order. If character does not exists in the string
*	does not exists in the string, it return NULL.
*
*	s (const char *): string.
*	c (int): character need to be checked in the string.
*
*	returns: the addrress of the first occurrence of
*			the character in the string in reverse order
*			else NULL.
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
