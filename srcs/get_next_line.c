#include "get_next_line.h"

void	initialize_mem(t_read *line)
{
	line->mem_size = 2;
	line->str = NULL;
	line->len = 0;
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

void	append_char(t_read *line, char c)
{
	char	*temp;

	if (!line->str)
		line->str = malloc(line->mem_size);
	else if (line->len + 2 > line->mem_size)
	{
		temp = malloc(line->mem_size);
		temp = ft_strcpy(line->str, temp);
		free(line->str);
		line->mem_size *= 2;
		line->str = malloc(line->mem_size);
		line->str = ft_strcpy(temp, line->str);
		free(temp);
	}
	line->str[line->len++] = c;
	line->str[line->len] = '\0';
}

char	*get_next_line(int fd)
{
	t_read	*line;
	t_uint	bytes;
	char	*str;
	char	c;

	bytes = read(fd, &c, 1);
	if (bytes)
	{
		line = malloc(sizeof(t_read));
		initialize_mem(line);
		append_char(line, c);
	}
	else if (bytes == 0 || fd < 0)
		return (NULL);
	while (bytes && c != '\n' && c != '\0' && line->len < BUFFER_SIZE)
	{
		bytes = read(fd, &c, 1);
		if (bytes)
			append_char(line, c);
	}
	append_char(line, '\0');
	str = malloc(line->len + 1);
	str = ft_strcpy(line->str, str);
	if (line->str)
		free(line->str);
	free(line);
	return (str);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*file_path1;
	char	*file_path2;
	char	*line;

	file_path1 = "test/test1.txt";
	fd1 = open(file_path1, O_RDONLY);
	// while ((line = get_next_line(fd1)))
	// {
	// 	if (!line)
	// 		break;
	// 	printf("%s", line);
	// 	free(line);
	// }
	// close(fd1);
	file_path2 = "test/test2.txt";
	fd2 = open(file_path2, O_RDONLY);
	// while ((line = get_next_line(fd2)))
	// {
	// 	if (!line)
	// 		break;
	// 	printf("%s", line);
	// 	free(line);
	// }
	// close(fd2);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	line = get_next_line(fd2);
	printf("%s", line);
	free(line);
}