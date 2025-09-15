/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 23:45:34 by sudas             #+#    #+#             */
/*   Updated: 2025/09/15 23:45:34 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	t_uint	i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

int	is_char_in_str(char *stach, char c)
{
	while (*stach)
	{
		if (*stach == c)
			return (1);
		stach++;
	}
	return (0);
}

char	*ft_strcpy(char *src, char *dst)
{
	t_uint	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

char	*ft_strcat(char *dest, char *src)
{
	t_uint	dest_len;
	t_uint	i;

	i = 0;
	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strdup_term(char *src, char term_char)
{
	t_uint	i;
	char	*copy;

	i = 0;
	while (src[i] != term_char && src[i] != '\0')
		i++;
	copy = malloc(i + 2);
	i = 0;
	while (src[i] != term_char && src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = src[i];
	copy[i + 1] = '\0';
	return (copy);
}
