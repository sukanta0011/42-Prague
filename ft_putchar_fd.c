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

/*
* Function: ft_split
* ------------------
*	Outputs the character ’c’ to the specified file
*	descriptor.

*	c: The character to output.
*	fd: The file descriptor on which to write.
*
*	return: none
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
