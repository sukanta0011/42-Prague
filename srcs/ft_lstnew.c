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

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

// int main(void)
// {
// 	t_list *start;
// 	char c = 'A';

// 	start = ft_lstnew(&c);
// 	for (int i = 0; start !=NULL; i++)
// 	{
// 		printf("%c", *(char *)start->content);
// 		start = start->next;
// 	}
// 	return (0);
// }