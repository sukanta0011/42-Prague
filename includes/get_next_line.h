#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 42

typedef unsigned int	t_uint;

typedef struct	s_read
{
	int		mem_size;
	char	*str;
	int		len;
}				t_read;

#endif