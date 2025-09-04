/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:16:34 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 16:42:24 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (size != 0 && i < size - 1)
		{
			dest[i] = src[i];
		}
		i++;
	}
	if (size > 0)
	{
		if (i < size - 1)
		{
			dest[i] = '\0';
		}
		else
		{
			dest[size - 1] = '\0';
		}
	}
	return (i);
}

// int	main(void)
// {
// 	char str[] = "12345697";
// 	char copy_str[100] = "kgfkdsagfkasfgafadglaafl";
// 	int str_len;

// 	str_len = ft_strlcpy(copy_str, str, 0);
// 	// printf("%s\n", str);
// 	printf("%s\n", copy_str);
// 	printf("\n%d", str_len);
// }