/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:49:34 by sudas             #+#    #+#             */
/*   Updated: 2025/09/26 13:49:34 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_stack(t_dll_info *lst_a, t_dll_info *lst_b)
{
	if ((lst_a->head->index > lst_a->head->next->index)
		&& (lst_a->head->index > lst_a->tail->index))
		operation(lst_a, lst_b, "ra");
	else if ((lst_a->head->next->index > lst_a->head->index)
		&& (lst_a->head->next->index > lst_a->tail->index))
		operation(lst_a, lst_b, "rra");
	else if ((lst_a->head->next->index < lst_a->head->index)
		&& (lst_a->head->next->index > lst_a->tail->index))
		operation(lst_a, lst_b, "rra");
	if (lst_a->head->index > lst_a->head->next->index)
		operation(lst_a, lst_b, "sa");
}

void	fix_the_stack(t_dll_info *lst_a, t_dll_info *lst_b)
{
	if (lst_a->size >= 6)
	{
		operation(lst_a, lst_b, "rra");
		operation(lst_a, lst_b, "rra");
		operation(lst_a, lst_b, "rra");
	}
	if (lst_a->size == 5)
	{
		operation(lst_a, lst_b, "ra");
		operation(lst_a, lst_b, "ra");
	}
	if (lst_a->size == 4)
		operation(lst_a, lst_b, "ra");
}

void	sort_small_stack(t_dll_info *lst_a, t_dll_info *lst_b)
{
	while (lst_a->size > 3)
	{
		if (lst_a->head->index >= 3)
			operation(lst_a, lst_b, "pb");
		else
			operation(lst_a, lst_b, "ra");
	}
	sort_three_stack(lst_a, lst_b);
	empty_stack_b(lst_a, lst_b);
	fix_the_stack(lst_a, lst_b);
}

void	sort_stack(t_dll_info *lst_a, t_dll_info *lst_b)
{
	if (lst_a->size == 1 || is_asending(lst_a))
		return ;
	else if (lst_a->size <= 10)
		sort_small_stack(lst_a, lst_b);
	else
		chunk_sort(lst_a, lst_b);
}
