#include "libft.h"


t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	t_list	*head;

	if (!new_lst || !lst || !*f)
		return (NULL);
	head = new_lst;
	while (lst)
	{
		new_lst = malloc(sizeof(t_list));
		new_lst->content = f(lst->content);
		temp = lst->next;
		del(lst->content);
		free(del);
		new_lst = temp;
		lst = temp;
	}
	return (head);
}