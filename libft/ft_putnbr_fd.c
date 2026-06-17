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

/*
* Function: ft_split
* ------------------
*	Outputs the integer ’n’ to the specified file
*	descriptor

*	n: The integer to output.
*	fd: The file descriptor on which to write.
*
*	return: none
*/
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
