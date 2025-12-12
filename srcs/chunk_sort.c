/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:54:26 by sudas             #+#    #+#             */
/*   Updated: 2025/09/29 14:54:26 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size (int size)
{
	if (size <= 7)
		return (2);
	if (size > 7 && size <= 10)
		return (4);
	if (size > 10 && size <= 40)
		return (10);
	if (size > 40 && size <= 100)
		return (20);
	if (size > 100)
		return (35);
	return (-1);
}

void	empty_stack_b(t_dll_info *lst_a, t_dll_info *lst_b)
{
	int	idx;

	while (lst_b->size > 0)
	{
		idx = find_largest_in_b(lst_b);
		if (idx <= lst_b->size / 2)
			while (idx-- > 0)
				operation(lst_a, lst_b, "rb");
		else
		{
			while (idx++ < lst_b->size)
				operation(lst_a, lst_b, "rrb");
		}
		operation(lst_a, lst_b, "pa");
	}
}

void	chunk_sort(t_dll_info *lst_a, t_dll_info *lst_b)
{
	int	n;
	int	i;
	int	chunk;

	i = 0;
	n = lst_a->size;
	chunk = get_chunk_size(n);
	while (lst_a->size > 0)
	{
		if (lst_a->head->index <= i)
		{
			operation(lst_a, lst_b, "pb");
			operation(lst_a, lst_b, "rb");
			i++;
		}
		else if (lst_a->head->index <= i + chunk)
		{
			operation(lst_a, lst_b, "pb");
			i++;
		}
		else
			operation(lst_a, lst_b, "ra");
	}
	empty_stack_b(lst_a, lst_b);
}
