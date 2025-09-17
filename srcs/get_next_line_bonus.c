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

char	*get_line(t_uint bytes, char *stash)
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

char	**realloc_dblptr(char **str, t_uint old_size, t_uint new_size)
{
	char	**temp;
	t_uint	i;

	temp = malloc(sizeof(char *) * new_size);
	i = 0;
	while (i < old_size)
	{
		if (str[i] != NULL)
		{
			temp[i] = ft_strdup_term(str[i], '\0');
			free(str[i]);
		}
		else
			temp[i] = NULL;
		i++;
	}
	while (i < new_size)
	{
		temp[i] = NULL;
		i++;
	}
	free(str);
	return (temp);
}

char	**realloc_ptrs(char **str, int fd)
{
	char	**temp;

	if (!str)
		str = realloc_dblptr(str, 0, 4);
	else if(!str[fd])
	{
		temp = realloc_dblptr(str, (fd + 1), (fd + 1));
		str = realloc_dblptr(temp, (fd + 1), (fd + 2));
	}
	return (str);
}

char	*get_next_line_bonus(int fd)
{
	t_uint		bytes;
	static char	**stash;
	char		*temp;
	char		*line;

	bytes = 1;
	stash = NULL;
	stash = realloc_ptrs(stash, fd);
	if (!stash[fd])
		stash[fd] = malloc(BUFFER_SIZE + 1);
	temp = malloc(BUFFER_SIZE + 1);
	while (bytes && !is_char_in_str(stash[fd], '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes)
		{
			temp[bytes] = '\0';
			stash[fd] = realloc_memory(stash[fd], (ft_strlen(stash[fd]) + BUFFER_SIZE), 0);
			stash[fd] = ft_strcat(stash[fd], temp);
		}
	}
	line = get_line(bytes, stash[fd]);
	stash[fd] = truncate_stash(stash[fd]);
	if (!line)
		free (stash[fd]);
	free (temp);
	return (line);
}

