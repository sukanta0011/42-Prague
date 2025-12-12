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

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dll_info	*lst_a_info = NULL;
	t_dll_info	*lst_b_info = NULL;
	int			*sorted_arr;

	if (argc < 2 || ft_strlen(argv[1]) == 0)
	{
		ft_puterror("Error");
		return (0);
	}
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = init_lst_info(lst_b_info);
	if (store_in_stack(argc, argv, lst_a_info))
	{
		// printf("sorting");
		sorted_arr = create_temp_array(lst_a_info);
		quick_sort(sorted_arr, 0, argc - 2);
		assign_index(lst_a_info, sorted_arr);
		sort_stack(lst_a_info, lst_b_info);
		
		// printf("%s\n", "-----------a-----------");
		// print_lst(lst_a_info);

		// if (is_asending(lst_a_info))
		// 	printf("Sorted\n");
		// else
		// 	printf("Not-Sorted\n");

		free(sorted_arr);
	}
	else
		ft_puterror("Error");
	free_lst(lst_a_info);
	free_lst(lst_b_info);
	return (0);
}
