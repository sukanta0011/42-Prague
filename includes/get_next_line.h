#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
#endif

typedef unsigned int	t_uint;

int		ft_strlen(char *str);
int		is_char_in_str(char *stach, char c);
char	*ft_strcpy(char *src, char *dst);
char	*ft_strcat(char *dest, char *src);
char	*ft_strdup_term(char *src, char term_char);

char	*truncate_stach(char *stach);
char	*store_in_stach(char *stach, char *str);
char	*get_next_line(int fd);

#endif