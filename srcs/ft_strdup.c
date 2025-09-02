/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:24:49 by sudas             #+#    #+#             */
/*   Updated: 2025/08/21 09:47:59 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// int main(void)
// {
// 	char str[] = "hello ";
// 	char *dup_str;

// 	// printf("%s\n", copy);
// 	dup_str = ft_strdup(str);
// 	printf("%s\n", dup_str);
// 	free(dup_str);
// }