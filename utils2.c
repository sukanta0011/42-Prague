/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 10:06:41 by sudas             #+#    #+#             */
/*   Updated: 2025/09/11 10:06:41 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_padding_char(char pad, t_uint len)
{
	t_uint	i;

	i = 0;
	while ((int)i < (int)len)
	{
		ft_putchar(pad);
		i++;
	}
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

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && (s1[i] == s2[i]) && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	append_char(t_str *str_dtls, int c)
{
	char	*temp;

	if (!str_dtls->str)
		str_dtls->str = malloc(str_dtls->size);
	else if (str_dtls->len + 2 > str_dtls->size)
	{
		temp = malloc(str_dtls->size);
		ft_strcpy(str_dtls->str, temp);
		free(str_dtls->str);
		str_dtls->size *= 2;
		str_dtls->str = malloc(str_dtls->size);
		ft_strcpy(temp, str_dtls->str);
		free(temp);
	}
	str_dtls->str[str_dtls->len++] = c;
	str_dtls->str[str_dtls->len] = '\0';
}
