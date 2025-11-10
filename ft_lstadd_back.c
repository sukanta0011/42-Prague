/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:47:31 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 23:47:31 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_lstadd_front
* --------------------
*	Adds the node ’new’ at the end of the list.
*
*	lst: The address of a pointer to the first node of
*	a list.
*	new: The address of a pointer to the node to be
*	added
*
*	returns: none.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	head = *lst;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = head;
}

// int main(void)
// {
// 	t_list *start;
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
// 	for (int i = 0; start !=NULL; i++)
// 	{
// 		printf("%d\n", *(int *)start->content);
// 		start = start->next;
// 	}
// 	return (0);
// }