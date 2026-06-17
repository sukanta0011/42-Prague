/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:37:07 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 16:37:07 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	str_len;

	str_len = ft_strlen(s);
	write(fd, s, str_len);
	write(fd, "\n", 1);
}

// int main(void)
// {
// 	int		fd;
// 	char	c[] = "abcd fgh";

// 	fd = open("test.txt", O_RDWR);
// 	ft_putendl_fd(c, fd);
// 	close(fd);
// 	return (0);
// }