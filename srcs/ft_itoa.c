/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:48:43 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 14:48:43 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_num_len(int n)
{
	int				num_len;
	unsigned int	temp_num;

	if (n < 0)
		temp_num = -n;
	else
		temp_num = n;
	while (temp_num > 9)
	{
		num_len++;
		temp_num = temp_num / 10;
	}
	num_len++;
	return (num_len);
}

void	store_num(int n, char *arr, int pos)
{
	unsigned int	num;
	char			mod;

	if (n < 0)
	{
		num = -n;
		arr[0] = '-';
	}
	else
		num = n;
	if (num > 9)
	{
		store_num(num / 10, arr, pos - 1);
	}
	mod = (num % 10) + '0';
	arr[pos] = mod;
}

char	*ft_itoa(int n)
{
	char	*num_arr;
	int		num_len;

	num_len = get_num_len(n);
	if (n < 0)
		num_arr = malloc(sizeof(int) * (num_len + 2));
	else
	{
		num_arr = malloc(sizeof(int) * (num_len + 1));
		num_len--;
	}
	if (!num_arr)
		return (NULL);
	store_num(n, num_arr, num_len);
	num_arr[++num_len] = '\0';
	return (num_arr);
}
// int main(void)
// {
// 	int		n = 103456789;
// 	char	*arr;

// 	arr = ft_itoa(n);
// 	for(int i = 0; arr[i] != 0; i++)
// 		printf("%c", arr[i]);
// 	free (arr);
// }