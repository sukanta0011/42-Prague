/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:45:52 by sudas             #+#    #+#             */
/*   Updated: 2025/08/20 15:45:52 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strdup(char *src, int len)
{
	int		i;
	char	*copy;

	copy = malloc (sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	get_word_counts(char *str, char c)
{
	int	i;
	int	word_counts;

	i = 0;
	word_counts = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
			i++;
		word_counts++;
	}
	if (str[i - 1] == c)
		word_counts--;
	return (word_counts);
}

void	split_the_words(char *str, char c, char *str_arr[])
{
	int	i;
	int	start;
	int	word_len;
	int	j;

	i = 0;
	j = 0;
	word_len = 0;
	while (str[i] != '\0')
	{
		word_len = 0;
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] != c && str[i] != '\0')
		{
			word_len++;
			i++;
		}
		str_arr[j++] = ft_strdup(&str[start], word_len);
	}
	str_arr[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	int		word_counts;

	word_counts = get_word_counts ((char *)s, c);
	str_arr = malloc ((word_counts + 1) * sizeof(char *));
	if (str_arr == NULL)
		return (NULL);
	split_the_words ((char *)s, c, str_arr);
	return (str_arr);
}

int main(void)
{
	char str[] = "Hello   World, I am back  to coding; again";
	// char str[] = "";
	char charset = ' ';
	char **word_arr;
	int i;

	i = 0;
	word_arr = ft_split(str, charset);
	while (word_arr[i] != NULL)
	{
		printf("%s\n", word_arr[i]);
		free(word_arr[i]);
		i++;
	}
	free (word_arr);
	return 0;
}