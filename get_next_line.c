/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:56:14 by sudas             #+#    #+#             */
/*   Updated: 2025/09/15 13:56:14 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*truncate_stash(char *stash)
{
	t_uint	i;
	t_uint	stash_size;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	stash_size = ft_strlen(&stash[i]);
	// printf("%s %d, %d\n",stash, stash_size, i);
	stash = realloc_memory(stash, stash_size, i);
	// printf("Memory reallocated\n");
	return (stash);
}

char	*store_in_stash(char *stash, char *str)
{
	t_uint	stash_size;

	stash_size = ft_strlen(stash);
	stash = realloc_memory(stash, (stash_size + BUFFER_SIZE), 0);
	stash = ft_strcat(stash, str);
	return (stash);
}

char	*get_line(int bytes, char *stash)
{
	char	*line;

	if (!bytes && stash[0] == '\0')
		return (NULL);
	else if (is_char_in_str(stash, '\n'))
		line = ft_strdup_term(stash, '\n');
	else if (!bytes && !is_char_in_str(stash, '\n'))
		line = ft_strdup_term(stash, '\0');
	return (line);
}

// char	*get_line(int fd, char *stash)
// {
// 	char	*temp;
// 	int		bytes;

// 	bytes = 1;
// 	temp = malloc(BUFFER_SIZE + 1);
// 	if (!temp)
// 		return (NULL);
// 	while (bytes > 0 && !is_char_in_str(stash, '\n'))
// 	{
// 		bytes = read(fd, temp, BUFFER_SIZE);
// 		if (bytes > 0)
// 		{
// 			temp[bytes] = '\0';
// 			stash = store_in_stash(stash, temp);
// 		}
// 	}
// 	free (temp);
// 	if (bytes >= 0)
// 	{
// 		if (bytes >= 0 && stash[0] == '\0')
// 			return (NULL);
// 		else if (is_char_in_str(stash, '\n'))
// 			return (ft_strdup_term(stash, '\n'));
// 		else if (!is_char_in_str(stash, '\n'))
// 			return (ft_strdup_term(stash, '\0'));
// 	}
// 	return (NULL);
// }

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char	*temp;
	int		bytes;

	bytes = 1;
	if (fd < 0 || fd > 999)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		stash[0] = 0;
	}
	line  = NULL;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (bytes > 0 && !is_char_in_str(stash, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (stash);
			stash = NULL;
			free(temp);
			return (NULL);
		}
		if (bytes > 0)
		{
			temp[bytes] = '\0';
			stash = store_in_stash(stash, temp);
		}
	}
	if (bytes >= 0)
		line = get_line(bytes, stash);
	free(temp);
	if (!line)
	{
		free (stash);
		stash = NULL;
	}
	else
		stash = truncate_stash(stash);
	return (line);
}
