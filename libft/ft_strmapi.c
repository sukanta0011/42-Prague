/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:53:08 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 15:53:08 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strtrim
* --------------------
*	Applies the function f to each character of the
*	string s, passing its index as the first argument
*	and the character itself as the second. A new
*	string is created (using malloc(3)) to store the
*	results from the successive applications of f
*
*	s: The string to iterate over.
*	f: The function to apply to each character.
*
*	returns: The string created from the successive applications
*	of ’f’. Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				str_len;
	char			*new_str;
	unsigned int	i;

	str_len = ft_strlen((char *)s);
	new_str = malloc(str_len + 1);
	i = 0;
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
