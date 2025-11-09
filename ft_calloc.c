/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:06:47 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 21:06:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_calloc
* -------------------
*
*	Create a memory block of fixed size and assign null value
*	and return the memory address. If required memory size is more than
*	unsigned int then it return NULL. If required size or nmemb is
*	zero, it return unit memory block.
*
*	nmemb(size_t): number of memory block required
*	size(size_t): size of each memory block
*
*	return: the assigned memory block
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;
	size_t	max_size;
	size_t	required_memory;

	max_size = 4294967295;
	if (size > max_size / nmemb)
		return (NULL);
	required_memory = nmemb * size;
	if (nmemb == 0 || size == 0)
		required_memory = 1;
	memory = malloc(required_memory);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, required_memory);
	return (memory);
}
