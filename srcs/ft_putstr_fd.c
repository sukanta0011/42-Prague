/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:37:29 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 16:37:29 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	str_len;

	str_len = ft_strlen(s);
	write(fd, s, str_len);
}

// int main(void)
// {
// 	int		fd;
// 	char	c[] = "abcd fgh";

// 	fd = open("test.txt", O_RDWR);
// 	ft_putstr_fd(c, fd);
// 	close(fd);
// 	return (0);
// }