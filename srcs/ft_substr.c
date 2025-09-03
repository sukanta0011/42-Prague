/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 22:48:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/03 22:48:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	i = 0;
	sub_str = malloc(sizeof(char) * len);
	if (!sub_str)
		return (NULL);
	while (s[start + i] != '\0' && i < len - 1)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

// int main(void)
// {
// 	char str[] = "hello world0";
// 	char *sub_str;

// 	sub_str = ft_substr(str, 3, 5);
// 	printf("%s\n", sub_str);
// 	free(sub_str);
// }