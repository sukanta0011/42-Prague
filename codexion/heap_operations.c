/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sudas <sudas@student.42prague.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:37:55 by sudas             #+#    #+#             */
/*   Updated: 2026/05/18 01:12:38 by sudas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	move_up(int index, t_request *list)
{
	int	parent_idx;

	while (index > 0)
	{
		parent_idx = parent(index);
		if (list[parent_idx].priority_key > list[index].priority_key)
		{
			swap_items(&list[parent_idx], &list[index]);
			index = parent_idx;
		}
		else
			break ;
	}
}

void	move_down(int index, int size, t_request *list)
{
	int	min_index;
	int	l;
	int	r;

	min_index = index;
	l = left_child(index);
	if (l < size
		&& list[min_index].priority_key > list[l].priority_key)
		min_index = l;
	r = right_child(index);
	if (r < size
		&& list[min_index].priority_key > list[r].priority_key)
		min_index = r;
	if (index != min_index)
	{
		swap_items(&list[index], &list[min_index]);
		move_down(min_index, size, list);
	}
}

void	push(int coder_id, long priority_key, t_heap *heap)
{
	heap->requests[heap->size].coder_id = coder_id;
	heap->requests[heap->size].priority_key = priority_key;
	move_up(heap->size, heap->requests);
	heap->size++;
}

void	pop(t_heap *heap)
{
	if (heap->size == 0)
		return ;
	swap_items(&heap->requests[0],
		&heap->requests[heap->size - 1]);
	heap->size--;
	move_down(0, heap->size, heap->requests);
}

// int min_heap_tester()
// {
//     t_request *arr;
//     t_heap *heap;
//     int i;

//     arr = malloc(sizeof(t_request) * 2);
//     heap = malloc(sizeof(t_heap));

//     heap->requests = arr;
//     heap->capacity = 2;
//     heap->size = 0;

//     push(1, 15, heap);
//     push(2, 19, heap);

//     for(i=0; i < 2; i++)
//         printf("coder: %d, Key: %ld\n",
// 				arr[i].coder_id, arr[i].priority_key);

//     printf("Pop operations\n");
//     pop(heap);
//     printf("High priority: %ld\n", heap->requests[0].priority_key);

//     push(1, 30, heap);
// 	pop(heap);
// 	push(2, 40, heap);

// 	for(i=0; i < 2; i++)
//         printf("coder: %d, Key: %ld\n",
// 			arr[i].coder_id, arr[i].priority_key);

//     free(arr);
//     free(heap);

//     return 0;
// }

// int main()
// {
// 	min_heap_tester();
// 	return 0;
// }