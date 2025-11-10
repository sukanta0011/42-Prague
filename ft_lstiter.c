/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 00:03:37 by sudas             #+#    #+#             */
/*   Updated: 2025/11/07 00:03:37 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_iter
* --------------------
*	Iterates through the list ’lst’ and applies the
*	function ’f’ to the content of each node.
*
*	lst: The address of a pointer to a node.
*	f: The address of the function to apply to each
*	node’s content
*
*	returns: none.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*head;

	if (!lst || !f)
		return ;
	head = lst;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	lst = head;
}
