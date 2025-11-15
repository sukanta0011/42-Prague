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
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
	(*lst) = NULL;
}

// int main(void)
// {
// 	t_list *start;
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

// 	printf("Initial List: ");
// 	start = &a;
// 	for (int i = 0; start !=NULL; i++)
// 	{
// 		printf("%d, ", *(int *)start->content);
// 		start = start->next;
// 	}
// 	ft_lstclear(&start, free);
// 	if (start == NULL)
// 		printf("\nlist is empty\n");
// 	return (0);
// }