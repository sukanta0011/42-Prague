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

#include "get_next_line_bonus.h"

char	*truncate_stash(char *stash)
{
	t_uint	i;
	t_uint	stash_size;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	stash_size = ft_strlen(&stash[i]);
	stash = realloc_memory(stash, stash_size, i);
	return (stash);
}

char	*store_in_stash(char *stash, char *str)
{
	t_uint	stash_size;

	stash_size = ft_strlen(stash);
	stash = realloc_memory(stash, (stash_size + BUFFER_SIZE), 0);
	ft_strcat(stash, str);
	return (stash);
}

char	*get_line(int bytes, char *stash)
{
	char	*line;

	line = NULL;
	if (!bytes && stash[0] == '\0')
		return (NULL);
	else if (is_char_in_str(stash, '\n'))
		line = ft_strdup_term(stash, '\n');
	else if (!bytes && !is_char_in_str(stash, '\n'))
		line = ft_strdup_term(stash, '\0');
	return (line);
}

char	*get_next_line_extended(int fd, char **stash, char **temp)
{
	int		bytes;
	char	*line;

	bytes = 1;
	line = NULL;
	while (bytes > 0 && !is_char_in_str(*stash, '\n'))
	{
		bytes = read(fd, *temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (*stash);
			*stash = NULL;
			free(*temp);
			return (NULL);
		}
		if (bytes > 0)
		{
			(*temp)[bytes] = '\0';
			*stash = store_in_stash(*stash, *temp);
		}
	}
	if (bytes >= 0)
		line = get_line(bytes, *stash);
	free(*temp);
	return (line);
}

char	*get_next_line_bonus(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	char		*temp;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc(1);
		stash[fd][0] = 0;
	}
	line = NULL;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	line = get_next_line_extended(fd, &stash[fd], &temp);
	if (!line)
	{
		free (stash[fd]);
		stash[fd] = NULL;
	}
	else
		stash[fd] = truncate_stash(stash[fd]);
	return (line);
}
