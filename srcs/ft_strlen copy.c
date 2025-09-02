/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:20:34 by sudas             #+#    #+#             */
/*   Updated: 2025/08/13 15:05:41 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	int		char_counter;

	char_counter = 0;
	while (str[char_counter] != '\0')
		char_counter ++;
	return (char_counter);
}

// int main(void)
// {
//     char str[] = "abgrtrtcde";
// 	int str_len;

//     str_len = ft_strlen(str);
// 	printf("%d", str_len);
// }