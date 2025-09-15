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
	t_uint	j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
	{
		stash[j] = stash[i];
		i++;
		j++;
	}
	stash[j] = '\0';
	return (stash);
}

char	*store_in_stash(char *stash, char *str)
{
	char	*temp;
	t_uint	stash_size;

	stash_size = ft_strlen(stash);
	temp = malloc(stash_size + 1);
	temp = ft_strcpy(stash, temp);
	free(stash);
	stash = malloc(stash_size + BUFFER_SIZE + 1);
	stash[0] = '\0';
	stash = ft_strcat(stash, temp);
	free(temp);
	stash = ft_strcat(stash, str);
	return (stash);
}

char	*get_next_line(int fd)
{
	t_uint		bytes;
	static char	*stash;
	char		*temp;
	char		*line;

	bytes = 1;
	if (!stash)
	{
		stash = malloc(BUFFER_SIZE + 1);
		stash[0] = '\0';
	}
	temp = malloc(BUFFER_SIZE + 1);
	while (bytes && !is_char_in_str(stash, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes)
		{
			temp[BUFFER_SIZE] = '\0';
			stash = store_in_stash(stash, temp);
		}
	}
	if (!bytes && stash[0] == '\0')
	{
		free(temp);
		free(stash);
		return (NULL);
	}
	else if (is_char_in_str(stash, '\n'))
		line = ft_strdup_term(stash, '\n');
	else if (!bytes && !is_char_in_str(stash, '\n'))
		line = ft_strdup_term(stash, '\0');
	stash = truncate_stash(stash);
	free(temp);
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