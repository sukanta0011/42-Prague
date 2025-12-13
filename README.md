# Project: Push_Swap
This project has been created as part of the 42 curriculum by sudas42

## Description
The project required us to sort the provided arguments(integers) under the constrain that we can use only two empty stack (stack a and b) to store and sort the provided integers.

1. We need to parse the argument provide through the terminal. We have to make sure the arguments are valid integers else it should print Error on the terminal. If the provided arguments are valid, store it into stack a.

2. Now with the constrain of following operation we need to sort stack a with the help of stack b.
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one element or none.
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one element or none.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
- rrr : rra and rrb at the same time.

3. While sorting, we should keep printing the operation name on the terminal. At the end a check function will read the operation to check if with the provided operation, can it sort the same integers received by both our program and the checker function.

## Instructions
Run the make file to generate the push_swap binary.

Run ./push_swap 1 7 4 2 -11 to sort the array.

### Resources
- [42_Core_gitbook](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap/algorithms)
- [Sorting_algorithms](https://www.programiz.com/dsa/sorting-algorithm)
- AI usages: AI is used to understand how Radix sort and Chunk sort can be used in push_swap. In chunk sort, AI is used to optimize the chunk sort to reduce the number of steps below 5500 for sorting 500 numbers.

### Testers
1. [Tester1 -- used](https://github.com/gemartin99/Push-Swap-Tester)
2. [Tester2](https://github.com/LeoFu9487/push_swap_tester)

### Technique used
#### Indexing the numbers
Before starting the sorting by the operation allowed by the subject, I have used another temporary array and used Quick_Sort technique to sort the array. Then I used this sorted array as the reference to index the stack values.

Provided_list: 3, 4, 7, -10, 5

Sorted_array(index): -10(0), 3(1), 4(2), 5(3), 7(4)

Provided_list(index): 3(1), 4(2), 7(4), -10(0), 5(3)

#### Sorting small stack (<10 args)

For sorting 3 numbers, custom algorithm is used and max requirement of steps are 1 or 2. For numbers more than 3, I have used simple algorithm to find the index > 2 and push them one by one to stack b, Stack b is sorted in descending order, sort the smallest 3 number in stack in ascending order, then push back the values to stack a from b and rotate the stack a to make it sorted.

#### Sorting big stack (>10)

To sort big stack, the chunk sort is used where I have used chunk size 20 for 100 numbers and chunk size 35 for 500 numbers. The idea of chunk sort is, in stack a, the program look for the index value which falls between "i" and "i" + chunk, "i" starts from 0 and every time a match is found, i push the value to stack b, if the index fall below "i", i push it to chunk b and rotate the chunk b such that the smallest number goes at the bottom, and every time match is found, "i" is increased, else rotate the stack a. We do this until stack a is empty. While pushing back from b to a, i look for the largest number and try to find optimal way to bring that number at the top of the stack b and then push it. The initial filtering by chunks, helps in minimizing the steps required to make the stack b empty. The number of steps required to sort the array depends on chunk size also, I found that chunk 35 is optimal form 500 numbers and 20 for 100 numbers.

