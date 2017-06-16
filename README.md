# push_swap
An introduction to sorting algorithms.

Given a list a numbers in stack A and an empty stack B, the goal is to sort the list of numbers in ascending order and in the minimal amount of moves.

Only the following operations are allowed:

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.

rrr : rra and rrb at the same time.

Example (running with -v flag displays the movement):

./push_swap -v 1 5 2 4 3

Start:

a: 1 5 2 4 3

b:

ra

a: 5 2 4 3 1

b:

pb

a: 2 4 3 1

b: 5

ra

a: 4 3 1 2

b: 5

pb

a: 3 1 2

b: 4 5

ra

a: 1 2 3

b: 4 5

rb
a: 1 2 3
b: 5 4

pa

a: 5 1 2 3

b: 4

pa

a: 4 5 1 2 3

b:

ra

a: 5 1 2 3 4

b:

ra

a: 1 2 3 4 5

b:

Done: Steps=10
