/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:42:51 by sudas             #+#    #+#             */
/*   Updated: 2025/11/27 01:05:35 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// #include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd1;
	char	*file_path1;
	int		fd2;
	char	*file_path2;
	int		fd3;
	char	*file_path3;

	file_path1 = "test/test3";
	fd1 = open(file_path1, O_RDONLY);
	file_path2 = "test/test3";
	fd2 = open(file_path2, O_RDONLY);
	file_path3 = "test/test1";
	fd3 = open(file_path3, O_RDONLY);
	(void)fd3;
	// while ((line = get_next_line_bonus(fd1)))
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	// printf("fds: %d, %d, %d\n", fd1, fd2, fd3);

	
	// line = get_next_line_bonus(fd1);
	// printf("%s", line);
	// free(line);
	// while (line)
	// {
	// 	line = get_next_line_bonus(fd1);
	// 	printf("%s", line);
	// 	free(line);
	// }
	for (int i = 0; i < 8; i++)
	{
		line = get_next_line_bonus(fd1);
		printf("file1: %s", line);
		free(line);
		line = get_next_line_bonus(fd2);
		printf("file2: %s", line);
		free(line);
		// line = get_next_line_bonus(fd3);
		// printf("file3: %s", line);
		// free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
}