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

char **realloc_ptrs(char **str, int fd)
{
	char	**temp;
	t_uint	i;

	temp = malloc(sizeof(char *) * (fd + 1));
	i = 0;
	while (i < (fd + 1))
	{
		if (str[i] != NULL)
		{
			temp[i] = malloc(ft_strlen(str[i]) + 1);
			temp[i][0] = '\0';
			temp[i] = ft_strcat(temp[i], str[i]);
			printf("%s\n", str[i]);
			free(str[i]);
			printf("%s\n", str[i]);
		}
		else
			temp[i] = NULL;
		i++;
	}
	free(str);
	str = malloc(sizeof(char *) * (fd + 2));
	str[i] = NULL;
	while (i > 0)
	{
		i--;
		if (temp[i])
		{
			str[i] = malloc(ft_strlen(temp[i]) + 1);
			str[i][0] = '\0';
			str[i] = ft_strcat(str[i], temp[i]);
			free(temp[i]);
		}
		else
			str[i] = NULL;
	}
	free(temp);
	return (str);
}

int main(void)
{
	char	**str;
	int		fd;
	t_uint	i;

	fd = 3;
	str = malloc(sizeof(char *) * (fd + 1));
	str[0] = NULL;
	str[1] = NULL;
	str[2] = NULL;
	str[3] = NULL;
	str[0] = malloc(20);
	str[0] = "Hi";
	str[2] = malloc(10);
	str[2] = "World";
	if (!str[3])
	{
		str[3] = malloc(10);
		str[3] = "Sukanta";
	}
	str = realloc_ptrs(str, fd);
	if (!str[4])
	{
		str[4] = malloc(10);
		str[4] = "Das";
	}
	printf("%s %s %s\n", str[0], str[3], str[4]);
	i = 0;
	while(i < (fd + 2))
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}
