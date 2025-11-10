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

/*
* Function: ft_split
* ------------------
*	Outputs the string ’s’ to the specified file
*	descriptor followed by a newline

*	s: The string to output.
*	fd: The file descriptor on which to write.
*
*	return: none
*/
void	ft_putstr_fd(char *s, int fd)
{
	int	str_len;

	str_len = ft_strlen(s);
	write(fd, s, str_len);
}
