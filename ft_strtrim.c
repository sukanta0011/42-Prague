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

/*
* Function: get_word_end
* --------------------
*	Verify if the character is in the shared character set
*/
int	is_char_in_set(char c, char *set)
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

/*
* Function: get_word_end
* --------------------
*	Traverse the string skipping the character
*	with in the set and return the index of the
*	first encounter of character not in the set.
*/
int	get_word_start(char *s, char *set)
{
	int	i;

	i = 0;
	while (s[i] && is_char_in_set(s[i], set))
		i++;
	return (i);
}

/*
* Function: get_word_end
* --------------------
*	Traverse the string from the reverse direction skipping
*	the character with in the set and return the index of the
*	first encounter of character not in the set.
*/
int	get_word_end(char *s, char *set)
{
	int	i;
	int	str_len;

	str_len = ft_strlen(s);
	i = str_len - 1;
	while (i >= 0 && is_char_in_set(s[i], set))
		i--;
	return (i);
}

/*
* Function: ft_strtrim
* --------------------
*	Allocates memory (using malloc) and returns a
*	copy of ’s1’ with characters from ’set’ removed
*	from the beginning and the end.
*
*	s (char const *): the string to be trimmed.
*	set (char const *): characters need to be trimmed.
*
*	returns: trimmed string in a new memory block.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trimmed_str;

	start = get_word_start((char *)s1, (char *)set);
	if (start >= (int)ft_strlen((char *)s1))
		end = start - 1;
	else
		end = get_word_end((char *)s1, (char *)set);
	trimmed_str = malloc(end - start + 2);
	if (!trimmed_str)
		return (NULL);
	i = start;
	while (i <= end)
	{
		trimmed_str[i - start] = s1[i];
		i++;
	}
	trimmed_str[i - start] = '\0';
	return (trimmed_str);
}
