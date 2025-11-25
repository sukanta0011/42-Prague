/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:42:51 by sudas             #+#    #+#             */
/*   Updated: 2025/11/26 00:29:44 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line_bonus.h"
#include "get_next_line.h"

int	main(void)
{
	int		fd1;
	char	*file_path1;
	// int		fd2;
	// char	*file_path2;
	// int		fd3;
	// char	*file_path3;
	char	*line;

	file_path1 = "test/test1";
	fd1 = open(file_path1, O_RDONLY);
	// file_path2 = "test/test4.txt";
	// fd2 = open(file_path2, O_RDONLY);
	// file_path3 = "test/test1.txt";
	// fd3 = open(file_path3, O_RDONLY);
	// while ((line = get_next_line_bonus(fd1)))
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	// printf("fds: %d, %d, %d\n", fd1, fd2, fd3);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	while (line)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
	}
	
	// {
	// 	line = get_next_line(fd1);
	// 	printf("%s", line);
	// 	free(line);
	// 	// line = get_next_line_bonus(fd2);
	// 	// printf("file2: %s", line);
	// 	// free(line);
	// 	// line = get_next_line_bonus(fd3);
	// 	// printf("file3: %s", line);
	// 	// free(line);
	// }
	close(fd1);
	// close(fd2);
	// close(fd3);
}