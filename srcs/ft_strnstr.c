/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:05:41 by sudas             #+#    #+#             */
/*   Updated: 2025/09/03 21:03:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cal_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ndl_len;

	i = 0;
	ndl_len = cal_str_len((char *)needle);
	if (ndl_len == 0 || len == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (j < ndl_len && (j + i) < len && (haystack[i + j] == needle[j])
			&& haystack[j + i] != '\0')
			j++;
		if (j == ndl_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	// char str1[] = "ABghharhararfagahahahahCASAD";
// 	// char str2[] = "rh";
// 	char str3[] = "Hello world";
// 	char str4[] = "world";
// 	char *dest2;

// 	// dest1 = strnstr(str1, str2, 10);
// 	// printf("%s\n", dest1);
// 	dest2 = ft_strnstr(str3, str4, 9);
// 	if (dest2)
//         printf("Found: %s\n", dest2);
//     else
//         printf("Not found\n");
// }
