/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 21:04:55 by sudas             #+#    #+#             */
/*   Updated: 2025/09/16 21:04:55 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef unsigned int	t_uint;

int		ft_strlen(char *str);
int		is_char_in_str(char *str, char c);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup_term(char *src, char term_char);
char	*realloc_memory(char *str, t_uint new_size, t_uint pos);

char	*truncate_stash(char *stach);
char	*store_in_stash(char *stach, char *str);
char	*get_next_line(int fd);
char	*get_line(int bytes, char *stash);
// char	*get_line(int fd, char *stash);

#endif