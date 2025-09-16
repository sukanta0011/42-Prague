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
	stash = ft_strcat(stash, str);
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

char	*get_next_line(int fd)
{
	t_uint		bytes;
	static char	*stash;
	char		*temp;
	char		*line;

	bytes = 1;
	if (!stash)
		stash = malloc(BUFFER_SIZE + 1);
	temp = malloc(BUFFER_SIZE + 1);
	while (bytes && !is_char_in_str(stash, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes)
		{
			temp[bytes] = '\0';
			stash = store_in_stash(stash, temp);
		}
	}
	line = get_line(bytes, stash);
	stash = truncate_stash(stash);
	if (!line)
		free (stash);
	free (temp);
	return (line);
}

int	main(void)
{
	int		fd1;
	char	*file_path1;
	char	*line;

	file_path1 = "test/test1.txt";
	fd1 = open(file_path1, O_RDONLY);
	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
}
