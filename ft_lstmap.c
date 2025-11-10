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
*	Iterates through the list ’lst’, applies the
*	function ’f’ to each node’s content, and creates
*	a new list resulting of the successive applications
*	of the function ’f’. The ’del’ function is used to
*	delete the content of a node if needed.
*
*	lst: The address of a pointer to a node.
*	f: The address of the function applied to each
*	node’s content.
*	del: The address of the function used to delete a
*	node’s content if needed.
*
*	returns: the new list. NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	(void)del;
	head = lst;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	lst = head;
	return (new_lst);
}

// void	*foo(void *content)
// {
// 	*(int *)(content) = 2;
// 	return (content);
// }

// int main(void)
// {
// 	t_list	*start;
// 	t_list	*new_lst;
// 	int arr[] = {2, 3, 4, 5, 6};
// 	t_list a, b, c, d, new;
// 	a.content = &arr[0];
// 	b.content = &arr[1];
// 	c.content = &arr[2];
// 	d.content = &arr[3];
// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	d.next = NULL;

// 	new.content = &arr[4];
// 	new.next = NULL;

// 	start = &a;
// 	ft_lstadd_back(&start, &new);
// 	// for (int i = 0; start !=NULL; i++)
// 	// {
// 	// 	printf("%d\n", *(int *)start->content);
// 	// 	start = start->next;
// 	// }
// 	new_lst = ft_lstmap(start, foo, free);
// 	(void)new_lst;
// 	for (int i = 0; new_lst; i++)
// 	{
// 		printf("%d\n", *(int *)new_lst->content);
// 		new_lst = new_lst->next;
// 	}
// 	ft_lstclear(&new_lst, free);
// 	ft_lstclear(&start, free);
// 	return (0);
// }
