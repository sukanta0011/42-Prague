# Project: Push_Swap
This project has been created as part of the 42 curriculum by sudas42

## Description
The project required us to sort the provided arguments(integers) under the constraint that we can use only two empty stacks (stack a and b) to store and sort the provided integers.

### Parsing
We need to parse the argument provided through the terminal. We have to make sure the arguments are valid integers, else it should print an Error on the terminal. If the provided arguments are valid, store them in stack a.

### Sorting
Now, with the constraint of following operation, we need to sort stack a with the help of stack b.
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

### Output
While sorting, we should keep printing the operation name on the terminal with \n character. At the end, a check function will read the operation to check if, with the provided operation, it can sort the same integers received by both our program and the checker function.

### Bonus: Checker
The main program only print the operation it has performed, the checker function apply the same operations on the same stack and check if the operations are enough to make the stack a sorted. On success it returns "OK" else "KO" and if the provided arguments has some error, it print "Error"

## Instructions
Run the make file to generate the push_swap binary.

```bash
make or make all
./push_swap 1 7 4 2 -11 -> to sort the arguments
```

```bash
make bonus -> gebberate checker file
./push_swap 1 7 4 2 -11 | ./checker 1 7 4 2 -11
```

## Resources
- [42_Core_gitbook](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap/algorithms)
- [Sorting_algorithms](https://www.programiz.com/dsa/sorting-algorithm)
- AI usages: AI is used to understand how Radix sort and Chunk sort can be used in push_swap. In chunk sort, AI is used to optimize the chunk sort to reduce the number of steps to below 5500 for sorting 500 numbers.

### Testers
1. [Tester1 -- used](https://github.com/gemartin99/Push-Swap-Tester)
2. [Tester2](https://github.com/LeoFu9487/push_swap_tester)

## Technique used
### Indexing the numbers
Before starting the sorting by the operation allowed by the subject, I have used another temporary array and used the Quick_Sort technique to sort the array. Then I used this sorted array as the reference to index the stack values.

Provided_list: 3, 4, 7, -10, 5

Sorted_array(index): -10(0), 3(1), 4(2), 5(3), 7(4)

Provided_list(index): 3(1), 4(2), 7(4), -10(0), 5(3)

### Sorting small stack (<10 args)

For sorting 3 numbers, a custom algorithm is used, and the maximum number of steps is 1 or 2. For numbers more than 3, I have used a simple algorithm to find the index > 2 and push them one by one to stack b. Stack b is sorted in descending order. Sort the smallest 3 numbers in the stack in ascending order, then push back the values to stack a from b and rotate the stack a to make it sorted.

### Sorting big stack (> 10)

To sort a big stack, the chunk sort is used, where I have used chunk size 20 for 100 numbers and chunk size 35 for 500 numbers. The idea of chunk sort is, in stack a, the program look for the index value which falls between "i" and "i" + chunk, "i" starts from 0 and every time a match is found, program pushs the value to stack b, if the index fall below "i", program pushs it to chunk b and rotate the chunk b such that the smallest number goes at the bottom, and every time match is found, "i" is increased, else rotate the stack a. We do this until stack a is empty. While pushing back from b to a, program looks for the largest number and tries to find an optimal way to bring that number to the top of the stack b and then push it. The initial filtering by chunks helps in minimizing the steps required to make the stack b empty. The number of steps required to sort the array depends on the chunk size. I found that chunk 35 is optimal for 500 numbers and 20 for 100 numbers.



