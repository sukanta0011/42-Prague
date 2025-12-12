/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:55:06 by sudas             #+#    #+#             */
/*   Updated: 2025/09/29 14:55:06 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_dll_info *lst_a, t_dll_info *lst_b)
{
	int	i;
	int	max_bits;
	int	arr_size;
	int	counts;

	max_bits = 0;
	i = 0;
	arr_size = lst_a->size;
	while (((arr_size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		counts = 0;
		if (is_asending(lst_a))
			break;
		while (counts < arr_size)
		{
			if (((lst_a->head->index >> i) & 1) == 0)
				operation(lst_a, lst_b, "pb");
			else
				operation(lst_a, lst_b, "ra");
			counts++;
		}
		while (lst_b->size > 0)
			operation(lst_a, lst_b, "pa");
		i++;
	}
}
