/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:02:32 by sudas             #+#    #+#             */
/*   Updated: 2025/09/23 19:02:32 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_asending(t_dll_info *lst)
{
	t_dbl_ll	*current;

	current = lst->head;
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dll_info	*lst_a_info;
	t_dll_info	*lst_b_info;
	int			error;
	char		*line;

	error = 0;
	if (argc < 2 || ft_strlen(argv[1]) == 0)
		error = 1;
	lst_a_info = NULL;
	lst_b_info = NULL;
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = init_lst_info(lst_b_info);
	if (store_in_stack(argc, argv, lst_a_info) && !error)
	{
		while((line = get_next_line(0)))
		{
			ft_strlcpy(line, line, ft_strlen(line));
			operation(lst_a_info, lst_b_info, line);
		}
		if(is_asending(lst_a_info))
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else
		ft_puterror("Error");
	free_lst(lst_a_info);
	free_lst(lst_b_info);
	if (!line)
		free(line);
	return (0);
}
