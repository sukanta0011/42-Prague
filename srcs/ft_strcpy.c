/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:19:11 by sudas             #+#    #+#             */
/*   Updated: 2025/08/11 15:19:11 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

int	main(void)
{
	char str[] = "1234569";
	char copy_str[100] = "aagsgsgsthstsjsj";

	ft_strcpy(copy_str, str);
	printf("%s\n", str);
	printf("%s", copy_str);
}