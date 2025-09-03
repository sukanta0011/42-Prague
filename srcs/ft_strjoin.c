/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:04:28 by sudas             #+#    #+#             */
/*   Updated: 2025/09/03 23:04:28 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*merged_str;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	merged_str = malloc(sizeof(char) * (s1_len + s2_len +1));
	if (!merged_str)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		merged_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		merged_str[s1_len + i] = s2[i];
		i++;
	}
	merged_str[s1_len + i] = '\0';
	return (merged_str);
}

// int main(void)
// {
// 	char str1[] = "Hello";
// 	char str2[] = "World";
// 	char *merged_str;

// 	merged_str = ft_strjoin(str1, str2);
// 	printf("%s\n", merged_str);
// 	free(merged_str);
// }
