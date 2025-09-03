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

size_t	max_size(size_t size)
{
	size_t	i;
	size_t	max_value;

	i = 1;
	max_value = 1;
	while (i < (size - 1))
	{
		max_value = 2 * max_value;
		i++;
	}
	return (max_value * 2 - 1);
}

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

void	*calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb == 0 && size == 0)
		return (NULL);
	else if (nmemb > max_size(sizeof(int) * 8) / size)
		return (NULL);
	else
		memory = malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, nmemb * size);
	return (memory);
}

// int main(void)
// {
// 	return (0);
// }