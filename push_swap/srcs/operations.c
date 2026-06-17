/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:19:03 by sudas             #+#    #+#             */
/*   Updated: 2025/09/22 23:19:03 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_dll_info *lst_info)
{
	t_dbl_ll	*temp;
	int			temp_num;

	temp = lst_info->head;
	if (lst_info->size > 1)
	{
		temp_num = temp->data;
		temp->data = temp->next->data;
		temp->next->data = temp_num;
	}
	return (1);
}

int	push(t_dll_info *src_info, t_dll_info *dst_info)
{
	t_dbl_ll	*src;
	t_dbl_ll	*dst;

	if (!src_info->head || src_info->size < 1)
		return (1);
	src = src_info->head;
	src_info->head = src->next;
	if (src_info->head)
		src_info->head->prev = NULL;
	else
		src_info->tail = NULL;
	src_info->size--;
	dst = dst_info->head;
	src->next = dst;
	if (dst)
		dst->prev = src;
	else
		dst_info->tail = src;
	dst_info->head = src;
	dst_info->size++;
	return (1);
}

int	rotate(t_dll_info *lst_info)
{
	t_dbl_ll	*head;
	t_dbl_ll	*tail;

	if (!lst_info->head)
		return (1);
	if (lst_info->size > 1)
	{
		head = lst_info->head;
		tail = lst_info->tail;
		lst_info->head = head->next;
		lst_info->head->prev = NULL;
		head->next = NULL;
		head->prev = tail;
		tail->next = head;
		lst_info->tail = head;
	}
	return (1);
}

int	reverse_rotate(t_dll_info *lst_info)
{
	t_dbl_ll	*head;
	t_dbl_ll	*tail;

	if (!lst_info->head)
		return (1);
	if (lst_info->size > 1)
	{
		head = lst_info->head;
		tail = lst_info->tail;
		lst_info->tail = tail->prev;
		lst_info->tail->next = NULL;
		tail->next = head;
		tail->prev = NULL;
		head->prev = tail;
		lst_info->head = tail;
	}
	return (1);
}

int	operation(t_dll_info *lst_a, t_dll_info *lst_b, char *instruct)
{
	ft_putstr(instruct);
	if (!ft_strcmp(instruct, "sa"))
		return (swap(lst_a));
	if (!ft_strcmp(instruct, "sb"))
		return (swap(lst_b));
	if (!ft_strcmp(instruct, "ss"))
		return (swap(lst_a) && swap(lst_b));
	if (!ft_strcmp(instruct, "pa"))
		return (push(lst_b, lst_a));
	if (!ft_strcmp(instruct, "pb"))
		return (push(lst_a, lst_b));
	if (!ft_strcmp(instruct, "ra"))
		return (rotate(lst_a));
	if (!ft_strcmp(instruct, "rb"))
		return (rotate(lst_b));
	if (!ft_strcmp(instruct, "rr"))
		return (rotate(lst_a) && rotate(lst_b));
	if (!ft_strcmp(instruct, "rra"))
		return (reverse_rotate(lst_a));
	if (!ft_strcmp(instruct, "rrb"))
		return (reverse_rotate(lst_b));
	if (!ft_strcmp(instruct, "rrr"))
		return (reverse_rotate(lst_a) && reverse_rotate(lst_b));
	return (0);
}
