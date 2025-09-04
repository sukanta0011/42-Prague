/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 16:36:18 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 16:36:18 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	char			mod;

	if (n < 0)
	{
		num = -n;
		write(fd, "-", 1);
	}
	else
		num = n;
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	mod = (num % 10) + '0';
	write(fd, &mod, 1);
}

// int main(void)
// {
// 	int		n = 103456789;
// 	int		fd;

// 	fd = open("test.txt", O_RDWR);
// 	ft_putnbr_fd(n, fd);
// 	close(fd);
// }
