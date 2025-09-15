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

int	is_char_in_str(char *stach, char c)
{
	while (*stach)
	{
		if (*stach == c)
			return (1);
		stach++;
	}
	return (0);
}

char	*ft_strcpy(char *src, char *dst)
{
	t_uint	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

char	*ft_strcat(char *dest, char *src)
{
	t_uint	dest_len;
	t_uint	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	dest_len = i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strdup_term(char *src, char term_char)
{
	t_uint	i;
	char	*copy;

	i = 0;
	while (src[i] != term_char && src[i] != '\0')
		i++;
	copy = malloc(i + 2);
	i = 0;
	while (src[i] != term_char && src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = src[i];
	copy[i + 1] = '\0';
	return (copy);
}

char	*truncate_stach(char *stach)
{
	t_uint	i;
	t_uint	j;

	i = 0;
	j = 0;
	while (stach[i] != '\n' && stach[i] != '\0')
		i++;
	if (stach[i] == '\n')
		i++;
	while (stach[i] != '\0')
	{
		stach[j] = stach[i];
		i++;
		j++;
	}
	stach[j] = '\0';
	return (stach);
}

char	*store_in_stach(char *stach, char *str, int size)
{
	char	*temp;
	t_uint	i;

	i = 0;
	while (stach[i] != '\0')
		i++;
	if (i == 0)
		stach = ft_strcpy(str, stach);
	else
	{
		temp = malloc(i + 1);
		temp = ft_strcpy(stach, temp);
		free(stach);
		stach = malloc(i + size + 1);
		stach[0] = '\0';
		stach = ft_strcat(stach, temp);
		free(temp);
		stach = ft_strcat(stach, str);
	}
	return (stach);
}

char	*get_next_line(int fd)
{
	t_uint		bytes;
	static char	*stach;
	char		*temp;
	char		*line;

	temp = malloc(BUFFER_SIZE + 1);
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes)
	{
		temp[bytes] = '\0';
		if (!stach)
			stach = malloc(bytes + 1);
		stach = store_in_stach(stach, temp, (bytes + 1));
		free (temp);
	}
	else
	{
		free (temp);
		if (stach[0] == '\0')
		{
			free (stach);
			return (NULL);
		}
	}
	if (is_char_in_str(stach, '\n'))
	{
		line = ft_strdup_term(stach, '\n');
		stach = truncate_stach(stach);
	}
	else if (!bytes && !is_char_in_str(stach, '\n'))
	{
		line = ft_strdup_term(stach, '\0');
		stach = truncate_stach(stach);
	}
	else
	{
		line = malloc(1);
		line[0] = '\0';
	}
	return (line);
}

int	main(void)
{
	int		fd1;
	char	*file_path1;
	char	*line;

	file_path1 = "test/test3.txt";
	fd1 = open(file_path1, O_RDONLY);
	while ((line = get_next_line(fd1)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd1);
}