/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:25:40 by sudas             #+#    #+#             */
/*   Updated: 2025/09/29 13:25:40 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_dll_info *lst_info)
{
	t_dbl_ll	*temp;
	t_dbl_ll	*next;

	temp = lst_info->head;
	while (temp)
	{
		next = temp->next;
		free (temp);
		temp = next;
	}
	free(lst_info);
}
