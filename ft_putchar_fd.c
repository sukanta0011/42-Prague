/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:37:45 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 16:37:45 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
// 	int		fd;
// 	char	c = 'a';

// 	fd = open("test.txt", O_RDWR);
// 	ft_putchar_fd(c, fd);
// 	close(fd);
// 	return (0);
// }