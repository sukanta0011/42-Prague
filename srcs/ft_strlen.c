/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 14:20:34 by sudas             #+#    #+#             */
/*   Updated: 2025/08/10 14:20:34 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	char	character;
	int		char_counter;

	character = *str;
	char_counter = 0;
	while (character != '\0')
	{
		str = str + 1;
		character = *str;
		char_counter ++;
	}
	return (char_counter);
}

// int main(void)
// {
//     char str[6] = {'a', 'd', 'e', '5', 'l'};
// 	int str_len;

//     str_len = ft_putstr(&str[0]);
// 	printf("%d", str_len);
// }