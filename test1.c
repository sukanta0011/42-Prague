#include <stdio.h>
#include <stdlib.h>

typedef unsigned int	t_uint;

int	ft_strlen(char *str)
{
	t_uint	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	t_uint	dest_len;
	t_uint	i;

	dest_len = ft_strlen(dest);
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
	t_uint	i;

	i = 0;
	if (!str)
	{
		str = realloc_dblptr(str, 0, 4);
	}
	else if(!str[fd])
	{
		temp = realloc_dblptr(str, (fd + 1), (fd + 1));
		str = realloc_dblptr(temp, (fd + 1), (fd + 2));
	}
	return (str);
}


int main(void)
{
	char	**str;
	int		fd;
	t_uint	i;

	fd = 3;
	str = NULL;
	str = realloc_ptrs(str, 3);
	str[0] = ft_strdup_term("Hi", '\0');
	str[2] = ft_strdup_term("World", '\0');
	if (!str[3])
		str[3] = ft_strdup_term("Sukanta", '\0');
	str = realloc_ptrs(str, fd+1);
	if (!str[4])
		str[4] = ft_strdup_term("Das", '\0');
	str = realloc_ptrs(str, fd + 2);
	if (!str[5])
		str[5] = ft_strdup_term("How", '\0');
	printf("%s %s %s %s\n", str[0], str[3], str[4], str[5]);
	i = 0;
	while(i < (fd + 3))
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}
