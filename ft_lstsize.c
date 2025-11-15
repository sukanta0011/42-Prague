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
* Function: ft_lstsize
* --------------------
*	Counts the number of nodes in the list.
*
*	lst: The beginning of the list.
*
*	returns: the length of the list
*/
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	t_list *start;
// 	int arr[] = {2, 3, 4, 5, 6};
// 	t_list a, b, c, d;
// 	int size;

// 	a.content = &arr[0];
// 	b.content = &arr[1];
// 	c.content = &arr[2];
// 	d.content = &arr[3];
// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	d.next = NULL;

// 	start = &a;
// 	size = ft_lstsize(start);
// 	printf("%d\n", size);
// 	return (0);
// }