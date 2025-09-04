/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:59:18 by sudas             #+#    #+#             */
/*   Updated: 2025/09/04 22:59:18 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	*lst = new;
	(*lst)->next = temp;
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
// 	ft_lstadd_front(&start, &new);
// 	for (int i = 0; start !=NULL; i++)
// 	{
// 		printf("%d\n", *(int *)start->content);
// 		start = start->next;
// 	}
// 	return (0);
// }