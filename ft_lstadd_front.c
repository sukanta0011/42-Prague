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

/*
* Function: ft_lstadd_front
* --------------------
*	Allocates memory (using malloc(3)) and returns
*	a new node. The ’content’ member variable is
*	initialized with the given parameter ’content’.
*	The variable ’next’ is initialized to NULL.
*
*	content: The content to store in the new node.
*
*	returns: A pointer to the new node
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	*lst = new;
	(*lst)->next = head;
}
