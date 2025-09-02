#include "libft.h"
#include <string.h>
#include <stdio.h>

// void *memset(void s, int c, size_t n)
// {

// }

int	main(void)
{
	char str[] = "Hello worlds";

	printf("%s\n", str);
	memset(&str[5], 1, 4 * sizeof(int));
	printf("%s\n", str);
}