/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:18:32 by sudas             #+#    #+#             */
/*   Updated: 2025/09/06 00:18:32 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Function: ft_lstadd_front
* --------------------
*	Takes a node as parameter and frees its content
*	using the function ’del’. Free the node itself but
*	does NOT free the next node.
*
*	lst: The node to free.
*	del: The address of the function used to delete
*	the content.
*
*	returns: none.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst->content);
	free (lst);
}

// int main(void)
// {
// 	t_list *last;
// 	int arr[] = {2, 3, 4, 5, 6};
// 	t_list a, b, c, d;

// 	a.content = &arr[0];
// 	b.content = &arr[1];
// 	c.content = &arr[2];
// 	d.content = &arr[3];
// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	d.next = NULL;

// 	last = &a;

// 	ft_lstdelone(&b);
// 	for (int i = 0; last !=NULL; i++)
// 	{
// 		printf("%d\n", *(int *)last->content);
// 		last = last->next;
// 	}
// 	return (0);
// }