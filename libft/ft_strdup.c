/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:24:49 by sudas             #+#    #+#             */
/*   Updated: 2025/11/09 21:53:36 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_strdup
* --------------------
*	Copy the provided string into new memory block and
*	return the new memory address.
*
*	src (char *): string to be copied.
*
*	returns: address of the new memory block with copied string.
*/
char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
