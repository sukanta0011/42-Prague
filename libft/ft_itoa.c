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

/*
* Function: get_num_len
* --------------------
*	Return the required size if we want to store each
*	digit of the integer inside an character array.
*
*/
int	get_num_len(int n)
{
	int				num_len;
	unsigned int	temp_num;

	num_len = 0;
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

/*
* Function: store_num
* --------------------
*	Divide the number by 10 and store the modulo in the array
*	using recursion.
*
*/
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

/*
* Function: ft_itoa
* --------------------
*	Allocates memory (using malloc) and returns
*	a string representing the integer received as an
*	argument. Negative numbers must be handled.
*
*	n (int): The integer to convert.
*
*	returns: The string representing the integer.
*	NULL if the allocation fails.
*/
char	*ft_itoa(int n)
{
	char	*num_arr;
	int		num_len;

	num_len = get_num_len(n);
	if (n < 0)
		num_arr = malloc(sizeof(char) * (num_len + 2));
	else
	{
		num_arr = malloc(sizeof(char) * (num_len + 1));
		num_len--;
	}
	if (!num_arr)
		return (NULL);
	store_num(n, num_arr, num_len);
	num_arr[++num_len] = '\0';
	return (num_arr);
}
