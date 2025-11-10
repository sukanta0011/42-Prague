/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:02:30 by sudas             #+#    #+#             */
/*   Updated: 2025/11/07 00:02:30 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_clean
* --------------------
*	Deletes and frees the given node and all its
*	successors, using the function ’del’ and free.
*	Finally, set the pointer to the list to NULL.
*
*	lst: The address of a pointer to a node.
*	del: The address of the function used to delete
*	the content of the node.
*
*	returns: none.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		(*lst) = temp;
	}
	(*lst) = NULL;
}
