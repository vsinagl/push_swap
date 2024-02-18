#include "string.h"
#include "pushswap.h"

stack	*stack_init(int	*arr, size_t len, size_t head)
{
	stack	*p_stack;

	p_stack = (stack*)malloc(sizeof(stack));
	if (p_stack == NULL)
			return(NULL);
	p_stack->self = arr;
	p_stack->len = len;
	p_stack->head = head;
	return(p_stack);
}

void	test_swap()
{
	int stackA[5] = {1,2,3,4,5};
	int stackB[2] = {10,11};
	stack *p_stackA = (stack*)malloc(sizeof(stack));
	stack *p_stackB = (stack*)malloc(sizeof(stack));
	
	p_stackA->self = stackA;
	p_stackB->self = stackB;
	p_stackA->head = 4;
	p_stackB->head = 0;
	p_stackA->len = 5;
	p_stackB->len = 2;

	//test of swap operations
	printf("testo of sa:\n");
	printf("expected resutl: {1, 5, 2, 3, 4}\n");
	printf("result: ");
	swap(p_stackA);
	print_stack(p_stackA);
	printf("\n\ntest of sb: \nexpected result: {11, 10}\nresult: ");
	swap(p_stackB);
	print_stack(p_stackB);
	printf("\n\ntest of ss: \nexpected result: {5, 1, 2, 3, 4} {11, 10}\nresult: ");
	swap_both(p_stackA, p_stackB);
	print_stack(p_stackA);
	print_stack(p_stackB);
	printf("\n");
}

void	test_rotation()
{
	int stackA[5] = {1,2,3,4,5};
	int stackB[3] = {10,11,9};
	stack *p_stackA = stack_init(stackA, 5, 4);
	stack *p_stackB = stack_init(stackB, 3, 0);
	printf("INIT STACK VALUES\nA: ");
	print_stack(p_stackA);
	printf("\nB: ");
	print_stack(p_stackB);
	printf("\n");
	printf("TEST OF rb:\nexpected result: {9, 10, 11}\ntest result: ");
	rotate(p_stackB);rotate(p_stackB);
	print_stack(p_stackB);
	printf("\n\nTEST OF ra:\nexpected result: {1, 2, 3, 4, 5}\ntest result ");
	rotate(p_stackA);
	print_stack(p_stackA);
	printf("\n\nTEST OF rra:\nexpected result: {5, 1, 2, 3, 4}\ntest result ");
	rev_rotate(p_stackA);
	print_stack(p_stackA);
	printf("\n");
}


int main()
{
	//test_swap();
	printf("\n");
	test_rotation();
	return(0);
}
	
