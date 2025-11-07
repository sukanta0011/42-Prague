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

int	get_word_strat(char *s, char *set)
{
	int	i;

	i = 0;
	while (s[i] && is_in_char_set(s[i], set))
		i++;
	return (i);
}

int	get_word_end(char *s, char *set)
{
	int	i;
	int	str_len;

	str_len = ft_strlen(s);
	i = str_len - 1;
	while (i >= 0 && is_in_char_set(s[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed_str;

	start = get_word_strat((char *)s1, (char *)set);
	end = get_word_end((char *)s1, (char *)set);
	trimmed_str = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	i = start;
	while (i <= end)
	{
		trimmed_str[i - start] = s1[i];
		i++;
	}
	trimmed_str[i] = '\0';
	return (trimmed_str);
}

// int main(void)
// {
// 	char s1[] = "   helo  oolo     ";
// 	char set[] = " o";
// 	char *trimmed;

// 	trimmed = ft_strtrim(s1, set);
// 	printf("%s\n", trimmed);
// 	free(trimmed);
// 	return (0);
// }