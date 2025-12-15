/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 17:54:41 by sudas             #+#    #+#             */
/*   Updated: 2025/11/08 15:34:56 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_isascii
* --------------------
*	verify if the provide char is ASCII (0-127) or not
*	c (int): character to verify.
*
*	returns:: 1->true, 0->false
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("%d\n", isascii(127));
// 	printf("%d\n", ft_isascii(127));
// }
