#include "string.h"
#include "pushswap.h"

int main()
{
	int stackA[5] = {1,2,3,4,5};
	int stackB[2] = {10,11};
	size_t len = 5; 
	size_t lenB = 2;
	size_t head = 4;
	size_t headB = 0;
	size_t *head_A = &head;

	//test of structure
	stack *p_stackA = (stack*)malloc(sizeof(stack));
	stack *p_stackB = (stack*)malloc(sizeof(stack));
	
	p_stackA->self = stackA;
	p_stackA->head = head;
	p_stackA->len = len;
	p_stackB->self = stackB;
	p_stackB->head = headB;
	p_stackB->len = lenB;
	//test for array overflow
	//swap(stackA, &head, len);
	swap_both(p_stackA, p_stackB);
	printf("test of array overflow:\narrayA: ");
	print_stack(p_stackA);
	printf("\n arrayB: "); 
	print_stack(p_stackB);

	return(0);
}
	
