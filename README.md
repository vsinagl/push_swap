This file is containg information about my solution of push swap project. 

# Goal of push swap
The push swap project is about sorting numbers using two stacks and defined operations with lowest numbers of operations as possible.

The program will at begining recieved the content of the first stack (A). The goal is to sort the numbers in first stack (A) by using the defined operations and second stack. The stack should be sorted in ascending folder, from lowest to biggets number.

The output of program is writing operations needed for sorting of stack A on standart output.

Allowed operations with stacks are:
- swaping
- rotating
- pushing

## Swaping
Swap operation swap the first two numbers in the stack, let's look at this example:
Stack A:
	4
	2
	3
	1
when we use `sa` function, we get:
	2
	4
	3
	1
we can use the swap function on stack A or stack B
the calls of operation are:
- `sa`: swap stack a
- `sb`: swap stack b

## Rotating
In rotation operation, we put the first item to the bottom or the bottom item to the top. The first mentioned is called "*rotation* (putting top item on stack to bottom). The second operation (putting the item from bottom to top) is called *reverse ration*.  
We can *rotate* or *reverse rotate* the stack A or stack B  
Example:  
stack B:  
	4  
	1  
	2  
	3  
`rB`  
stack B after rotation:  
	1  
	2  
	3  
	4  
the calls of operations are:  
- `rA`, `rB`: rotate stack A or B  
- `rrA`, `rrB`: reverse rotate stack A or B  
  
## Pushing
Pushing push the top element from stack to destination stack.  
for example:  
stack A:	stack B:  
	2  
	3  
	10  
`pB`  
stack A:	stack B:  
	3	2  
	10  
  
the calls of operations are:  
- `pa`: push stack from B to A  
- `pb`: push stack from A to B  

