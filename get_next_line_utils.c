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
	while (str[i])
		i++;
	return (i);
}

int	is_char_in_str(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strcat(char *dest, char *src)
{
	t_uint	dest_len;
	t_uint	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
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
	while (src[i] != term_char && src[i])
		i++;
	copy = malloc(i + 2);
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != term_char && src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = src[i];
	copy[i + 1] = '\0';
	return (copy);
}

char	*realloc_memory(char *str, t_uint new_size, t_uint pos)
{
	char	*temp;
	t_uint	str_size;

	str_size = ft_strlen(&str[pos]);
	temp = malloc(str_size + 1);
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	temp = ft_strcat(temp, &str[pos]);
	free(str);
	str = malloc(new_size + 1);
	if (!str)
	{
		free (temp);
		return (NULL);
	}
	str[0] = '\0';
	str = ft_strcat(str, temp);
	free(temp);
	return (str);
}
