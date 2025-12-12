/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 22:53:02 by sudas             #+#    #+#             */
/*   Updated: 2025/09/22 22:53:02 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef unsigned int	t_uint;

typedef struct s_dbl_ll
{
	int				data;
	int				index;
	struct s_dbl_ll	*next;
	struct s_dbl_ll	*prev;
}				t_dbl_ll;

typedef struct s_dll_info
{
	int			size;
	t_dbl_ll	*head;
	t_dbl_ll	*tail;
}				t_dll_info;

//======%% operation_swap %%=========
int			swap(t_dll_info *lst_info);
int			push(t_dll_info *src_info, t_dll_info *dst_info);
int			rotate(t_dll_info *lst_info);
int			reverse_rotate(t_dll_info *lst_info);
int			operation(t_dll_info *lst_a, t_dll_info *lst_b, char *instruct);

//======%% quick_sort %%=========
t_uint		swap_array_elements(int *arr, t_uint low, t_uint high);
void		quick_sort(int *arr, t_uint low, t_uint high);
int			*create_temp_array(t_dll_info *lst);

//======%% search_idx %%=========
int			find_index(int *sorted, int value, int low, int high);
int			find_from_top(t_dll_info *lst_a, int low, int high);
int			find_from_bottom(t_dll_info *lst_a, int low, int high);
int			find_largest_in_b(t_dll_info *lst_b);

//======%% operation_swap %%=========
void		sort_three_stack(t_dll_info *lst_a, t_dll_info *lst_b);
void		sort_stack(t_dll_info *lst_a, t_dll_info *lst_b);

//======%% radix_sort %%=========
void		radix_sort(t_dll_info *lst_a, t_dll_info *lst_b);

//======%% additional_func %%=========
void		print_lst(t_dll_info *lst_info);
void		print_lst_reverse(t_dll_info *lst_info);
int			is_asending(t_dll_info *lst);

//======%% chunk_sort %%=========
int			get_chunk_size (int size);
void		empty_stack_b(t_dll_info *lst_a, t_dll_info *lst_b);
void		chunk_sort(t_dll_info *lst_a, t_dll_info *lst_b);

//======%% utils1 %%=========
int			ft_strcmp(char *s1, char *s2);
int			str_to_num(char *str, long int *num);
void		ft_putstr(char *str);
void		ft_puterror(char *str);
int			ft_strlen(char *str);

//======%% lst_utils1 %%=========
t_dbl_ll	*create_node(int data);
t_dbl_ll	*add_at_back(t_dll_info *lst_info, int data);
t_dbl_ll	*add_at_front(t_dll_info *lst_info, int data);
t_dbl_ll	*del_front(t_dll_info *lst_info);
t_dll_info	*init_lst_info(t_dll_info *lst_info);

//======%% free_memory %%=========
void		free_lst(t_dll_info *lst_info);

//======%% parse_array %%=========
void		assign_index(t_dll_info *lst, int *sorted);
int			store_in_stack(int argc, char **argv, t_dll_info *lst_info);

#endif