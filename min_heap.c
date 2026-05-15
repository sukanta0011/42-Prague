#include "codexion.h"

int parent(int index)
{
    return (index - 1) / 2;
}


int left_child(int  index)
{
    return (2 * index + 1);
}


int right_child(int  index)
{
    return (2 * index + 2);
}


void	swap_items(t_request *item1, t_request *item2)
{
	int temp_coder_id;
	int	temp_priority_key;

	temp_coder_id = item1->coder_id;
	temp_priority_key = item1->priority_key;
	item1->coder_id = item2->coder_id;
	item1->priority_key = item2->priority_key;
	item2->coder_id = temp_coder_id;
	item2->priority_key = temp_priority_key;
}


void    move_up(int index, t_request *list)
{
    int parent_idx;

    while(index > 0)
    {
        parent_idx = parent(index);
        if(list[parent_idx].priority_key > list[index].priority_key)
        {
            swap_items(&list[parent_idx], &list[index]);
            index = parent_idx;
        }
        else
            break;
    }
}

void    move_down(int index, int size, t_request *list)
{
    int min_index;
    int l;
    int r;

    min_index = index;
    // printf("idx:%d\n", size);
    l = left_child(index);
    if (l < size &&\
        list[min_index].priority_key > list[l].priority_key)
        min_index = l;
    
    r = right_child(index);
    if (r < size &&\
        list[min_index].priority_key > list[r].priority_key)
        min_index = r;
        
    if (index != min_index)
    {
        swap_items(&list[index], &list[min_index]);
        move_down(min_index, size, list);
    }
}


void    push(int coder_id, long priority_key, t_heap *heap)
{
    heap->requests[heap->size].coder_id = coder_id;
    heap->requests[heap->size].priority_key = priority_key;
    move_up(heap->size, heap->requests);
    heap->size++;
}

void   pop(t_heap *heap)
{
    if (heap->size == 0)
        return;
    swap_items(&heap->requests[0], &heap->requests[heap->size - 1]);
    heap->size--;
    // printf("size: %d\n", heap->size);
    move_down(0, heap->size, heap->requests);
}


int main()
{
    t_request *arr;
    t_heap *heap;
    int i;

    arr = malloc(sizeof(t_request) * 6);
    heap = malloc(sizeof(t_heap));

    heap->requests = arr;
    heap->capacity = 6;
    heap->size = 0;

    push(1, 15, heap);
    push(2, 19, heap);
    push(3, 5, heap);
    push(4, 11, heap);
    push(5, 50, heap);
    push(6, 7, heap);
    for(i=0; i < 6; i++)
        printf("coder: %d, Key: %d\n", arr[i].coder_id, arr[i].priority_key);

    printf("Pop operations\n");
    pop(heap);
    printf("High priority: %ld\n", heap->requests[0].priority_key);

    pop(heap);
    printf("High priority: %ld\n", heap->requests[0].priority_key);

    pop(heap);
    printf("High priority: %ld\n", heap->requests[0].priority_key);

    for(i=0; i < 6; i++)
        printf("coder: %d, Key: %d\n", arr[i].coder_id, arr[i].priority_key);

    free(arr);
    free(heap);

    return 0;
}