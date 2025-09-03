/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 23:42:04 by sudas             #+#    #+#             */
/*   Updated: 2025/09/03 23:42:04 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_char_set(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		s1_len;
	int		counter;
	char	*trimmed_str;

	s1_len = ft_strlen((char *)s1);
	trimmed_str = malloc(sizeof(char) * (s1_len + 1));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	counter = 0;
	while (s1[i])
	{
		if (!is_in_char_set(s1[i], (char *)set))
		{
			trimmed_str[counter] = s1[i];
			counter++;
		}
		i++;
	}
	trimmed_str[counter] = '\0';
	return (trimmed_str);
}

// int main(void)
// {
// 	char s1[] = "   hello";
// 	char set[] = " o";
// 	char *trimmed;

// 	trimmed = ft_strtrim(s1, set);
// 	printf("%s\n", trimmed);
// 	free(trimmed);
// 	return (0);
// }