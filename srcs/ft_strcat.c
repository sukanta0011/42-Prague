/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:49:14 by sudas             #+#    #+#             */
/*   Updated: 2025/08/12 11:49:14 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <string.h>

int	cal_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = cal_str_len(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	char str1[10] = "ABCdggdfA";
// 	char str2[10] = "545";
// 	char str3[10] = "ABgdgdgCA";
// 	char str4[10] = "545";

// 	strcat(str2, str1);
// 	printf("%s\n", str2);
// 	ft_strcat(str4, str3);
// 	printf("%s\n", str4);
// }