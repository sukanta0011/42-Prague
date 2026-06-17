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

/*
* Function: ft_strndup
* -------------------------
*	This works similary to ft_strdup, but insted of
*	copping the full string, it only copy until the
*	provide length.
*/
char	*ft_strndup(char *src, int len)
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

/*
* Function: get_word_counts
* -------------------------
*	Split the string by delimiter and return the number
*	of splitted string.
*/
int	get_word_counts(char *str, char c)
{
	int	i;
	int	word_counts;

	i = 0;
	word_counts = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		while (str[i] != c && str[i])
			i++;
		word_counts++;
	}
	return (word_counts);
}

/*
* Function: split_the_words
* -------------------------
*	This is extension of ft_split function
*/
void	split_the_words(char *str, char c, char *str_arr[])
{
	int	i;
	int	start;
	int	word_len;
	int	j;

	i = 0;
	j = 0;
	word_len = 0;
	while (str[i])
	{
		word_len = 0;
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] != c && str[i])
		{
			word_len++;
			i++;
		}
		str_arr[j++] = ft_strndup(&str[start], word_len);
	}
	str_arr[j] = NULL;
}

/*
* Function: ft_split
* ------------------
*	split the long string into smaller string based on
*	the delimiter character.
*
*	s (char const *s): the string to be splitted.
*	c (char): the delimiter character
*
*	return: the array of new strings resulting from the
*	split. NULL if the allocation fails
*	
*	example:
*	ft_split("Hello World!", " ") -> ["Hello", "World!", NULL]
*	ft_split("Hello World!", "o") -> ["Hell", " W", "rld!", NULL]
*/
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
