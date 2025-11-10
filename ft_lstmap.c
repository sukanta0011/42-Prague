/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 23:59:06 by sudas             #+#    #+#             */
/*   Updated: 2025/11/06 23:59:06 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_lstmap
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
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_lst;
	t_list	*new_node;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = malloc(sizeof(t_list *));
	new_lst[0] = NULL;
	if (!new_lst)
		return (NULL);
	(void)del;
	head = lst;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		ft_lstadd_back(new_lst, new_node);
		lst = lst->next;
	}
	lst = head;
	return (*new_lst);
}
