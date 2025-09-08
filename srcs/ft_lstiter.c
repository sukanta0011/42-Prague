#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *head;

	if (!lst || !f)
		return ;
	head = lst;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
	lst = head;
}