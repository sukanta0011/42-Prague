/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 23:09:19 by sudas             #+#    #+#             */
/*   Updated: 2025/09/22 23:09:19 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dbl_ll	*create_node(int data)
{
	t_dbl_ll	*new_node;

	new_node = malloc(sizeof(t_dbl_ll));
	if (!new_node)
		return (NULL);
	new_node->prev = NULL;
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_dbl_ll	*add_at_back(t_dll_info *lst_info, int data)
{
	t_dbl_ll	*temp;
	t_dbl_ll	*new_node;

	new_node = create_node(data);
	temp = lst_info->tail;
	if (temp)
	{
		lst_info->tail = new_node;
		new_node->prev = temp;
		temp->next = new_node;
	}
	else
	{
		lst_info->head = new_node;
		lst_info->tail = new_node;
	}
	lst_info->size++;
	return (lst_info->head);
}

t_dbl_ll	*add_at_front(t_dll_info *lst_info, int data)
{
	t_dbl_ll	*temp;
	t_dbl_ll	*new_node;

	new_node = create_node(data);
	temp = lst_info->head;
	if (temp)
	{
		lst_info->head = new_node;
		temp->prev = new_node;
		new_node->next = temp;
	}
	else
	{
		lst_info->head = new_node;
		lst_info->tail = new_node;
	}
	lst_info->size++;
	return (lst_info->head);
}

t_dbl_ll	*del_front(t_dll_info *lst_info)
{
	t_dbl_ll	*temp;

	if (!lst_info || !lst_info->head)
		return (NULL);
	temp = lst_info->head;
	if (lst_info->size > 1)
	{
		lst_info->head = temp->next;
		temp->prev = NULL;
		temp->next = NULL;
	}
	else
	{
		lst_info->head = NULL;
		lst_info->tail = NULL;
	}
	free(temp);
	lst_info->size--;
	return (lst_info->head);
}

t_dll_info	*init_lst_info(t_dll_info *lst_info)
{
	lst_info = malloc(sizeof(t_dll_info));
	if (!lst_info)
		return (NULL);
	lst_info->head = NULL;
	lst_info->tail = NULL;
	lst_info->size = 0;
	return (lst_info);
}
