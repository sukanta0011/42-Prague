/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:15:39 by sudas             #+#    #+#             */
/*   Updated: 2025/11/09 01:07:45 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: isspace_char
* ----------------------
*	Verify if the provide character matches with any
*	any character between \t to \n or space (" ").
*	
*	c (int): character which need to be verified
*
*	return: 1->match, 0->does not match.
*/
int	isspace_char(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

/*
* Function: ft_atoi
* --------------------
*	It looked for the numeric character in the string until
*	there is any non-numeric character and convert the
*	initial numeric character into integer. It ignore
*	all the isspace character and space at the begining.
*
*	str (char *): address of string.
*
*	returns: if the provided string is a valid integer,
*	the string is converted to and integer and returned,
*	else it return 0.
*	
*	example:
*	ft_atoi(  +10bf50) -> 10;
*	ft_atoi(10bf50) -> 10;
*	ft_atoi(  -1050) -> -1050;
*	ft_atoi(  +a10bf50) -> 0;
*	ft_atoi(++10bf50) -> 0;
*/
int	ft_atoi(char *str)
{
	int			neg_counter;
	int			i;
	long int	num_int;

	i = 0;
	neg_counter = 1;
	num_int = 0;
	while (str[i] != '\0' && isspace_char(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg_counter = -neg_counter;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		num_int = num_int * 10 + (str[i] - '0');
		i++;
	}
	return (neg_counter * num_int);
}
