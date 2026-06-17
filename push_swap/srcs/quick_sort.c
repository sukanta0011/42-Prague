/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 10:28:22 by sudas             #+#    #+#             */
/*   Updated: 2025/09/26 10:28:22 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_temp_array(t_dll_info *lst)
{
	t_dbl_ll	*current;
	int			*arr;
	t_uint		i;

	current = lst->head;
	arr = malloc(sizeof(int) * lst->size);
	i = 0;
	if (!arr)
		return (NULL);
	while (current)
	{
		arr[i++] = current->data;
		current = current->next;
	}
	return (arr);
}

void	swap_values(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

t_uint	swap_array_elements(int *arr, t_uint low, t_uint high)
{
	t_uint	i;
	t_uint	j;
	int		pivot_value;

	i = low;
	j = low;
	pivot_value = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot_value)
		{
			swap_values(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap_values(&arr[i], &arr[high]);
	return (i);
}

void	quick_sort(int *arr, t_uint low, t_uint high)
{
	t_uint	pivot;

	if (low < high)
	{
		pivot = swap_array_elements(arr, low, high);
		if (pivot > 0)
			quick_sort(arr, low, pivot - 1);
		quick_sort(arr, pivot + 1, high);
	}
}
