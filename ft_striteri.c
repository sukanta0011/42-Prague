/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:37:04 by sudas             #+#    #+#             */
/*   Updated: 2025/11/06 23:37:04 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strtrim
* --------------------
*	Applies the function ’f’ to each character of the
*	string passed as argument, passing its index as
*	the first argument. Each character is passed by
*	address to ’f’ so it can be modified if necessary
*
*	s: The string to iterate over.
*	f: The function to apply to each character.
*
*	returns: none
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
