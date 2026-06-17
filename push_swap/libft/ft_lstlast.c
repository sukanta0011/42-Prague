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
* Function: ft_lstlast
* --------------------
*	Returns the last node of the list.
*
*	lst: The beginning of the list.
*
*	returns: Last node of the list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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

// 	last = ft_lstlast(&a);
// 	printf("Last element: %d\n", *(int *)last->content);
// 	return (0);
// }