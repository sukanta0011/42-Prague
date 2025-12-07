/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_idx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:22:59 by sudas             #+#    #+#             */
/*   Updated: 2025/09/29 14:22:59 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int *sorted, int value, int low, int high)
{
	int	mid;

	mid = low + (high - low) / 2;
	if (value == sorted[mid])
		return (mid);
	if (low <= high)
	{
		if (value > sorted[mid])
			return (find_index (sorted, value, mid + 1, high));
		else
			return (find_index (sorted, value, low, mid - 1));
	}
	return (-1);
}

int	find_from_top(t_dll_info *lst_a, int low, int high)
{
	t_dbl_ll	*cur;
	int			idx;

	idx = 0;
	cur = lst_a->head;
	while (cur)
	{
		if (cur->index >= low && cur->index <= high)
			return (idx);
		cur = cur->next;
		idx++;
	}
	return (-1);
}

int	find_from_bottom(t_dll_info *lst_a, int low, int high)
{
	t_dbl_ll	*cur;
	int			idx;

	idx = 1;
	cur = lst_a->tail;
	while (cur)
	{
		if (cur->index >= low && cur->index <= high)
			return (idx);
		cur = cur->prev;
		idx++;
	}
	return (-1);
}

int	find_largest_in_b(t_dll_info *lst_b)
{
	t_dbl_ll	*cur;
	int			idx;
	int			best_idx;
	int			max;

	cur = lst_b->head;
	idx = 0;
	best_idx = 0;
	max = cur->data;
	while (cur)
	{
		if (cur->data > max)
		{
			max = cur->data;
			best_idx = idx;
		}
		cur = cur->next;
		idx++;
	}
	return (best_idx);
}
