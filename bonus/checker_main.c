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

void	apply_ops_and_validate(t_dll_info *lst_a, t_dll_info *lst_b)
{
	int			error;
	char		*line;

	error = 0;
	line = get_next_line(0);
	while (line)
	{
		ft_strlcpy(line, line, ft_strlen(line));
		if (operation(lst_a, lst_b, line) == 0)
		{
			error = 1;
			break ;
		}
		line = get_next_line(0);
	}
	if (error)
		ft_puterror("Error");
	else if (is_asending(lst_a) && lst_b->size == 0)
		ft_putstr("OK");
	else
		ft_putstr("KO");
	if (!line)
		free(line);
}

int	main(int argc, char **argv)
{
	t_dll_info	*lst_a_info;
	t_dll_info	*lst_b_info;
	int			error;

	error = 0;
	if (argc < 2 || ft_strlen(argv[1]) == 0)
		error = 1;
	lst_a_info = NULL;
	lst_b_info = NULL;
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = init_lst_info(lst_b_info);
	if (store_in_stack(argc, argv, lst_a_info) && !error)
		apply_ops_and_validate(lst_a_info, lst_b_info);
	else
		ft_puterror("Error");
	free_lst(lst_a_info);
	free_lst(lst_b_info);
	return (0);
}
