/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 08:46:08 by marvin            #+#    #+#             */
/*   Updated: 2025/11/08 16:08:30 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_memset
* --------------------
*	fill the memory with constant byte
*
*	s (void *): pointer to the memory address
*	c (int): byte to be filled
*	n (size_t): number of memory chunks to 
*				be filled by provide byte
*
*	returns: pointer to the provided memory address
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
