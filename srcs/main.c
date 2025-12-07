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
	t_dll_info	*lst_a_info;
	t_dll_info	*lst_b_info;
	int			*sorted_arr;

	lst_a_info = NULL;
	lst_a_info = init_lst_info(lst_a_info);
	lst_b_info = NULL;
	lst_b_info = init_lst_info(lst_b_info);
	if (store_in_stack(argc, argv, lst_a_info))
	{
		sorted_arr = create_temp_array(lst_a_info);
		quick_sort(sorted_arr, 0, argc - 2);
		assign_index(lst_a_info, sorted_arr);
		sort_stack(lst_a_info, lst_b_info);
		// sort_small_stack(lst_a_info, lst_b_info);
		// sort_stack(lst_a_info, lst_b_info);
		// radix_sort(lst_a_info, lst_b_info);
		// printf("%s\n", "-----------a-----------");
		// print_lst(lst_a_info);

		// if (is_assending(lst_a_info))
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
