#include "../pushswap.h"

void	init_test()
{
	int stacklen = 8;
	int stack_arr[8] = {1,2,3,4,5,6,7,8};
	printf("UNIT TEST: testing stack_init function:\nTEST1: inicialization of array: {");
	for (int i = 0; i < stacklen; i++)
	{
		if (i < stacklen - 1)
			printf("%i, ",stack_arr[i]);
		else
			printf("%i}\n", stack_arr[i]);
	}
	printf("result of test:\n");
	t_stack *stack = stack_init(stack_arr, 8, 'A');
	printf("structure variables:\nhead->value: %i\n\thead->next: %p\n\thead->prev: %p\n\tlen: %li\nName of stack: %c\n",stack->head->value,stack->head->next, stack->head->prev, stack->len, stack->name);
	printf("printed stack: \n");
	print_stack(stack);
	printf("the head after print_stack function: %p: %i\n",stack->head, stack->head->value);
	
	//test 2 arr == NULL ale len > 0
	printf("\nTEST 2: arr = NULL, len > 1\n");
	int *stack_arr2 = NULL;
	printf("expected result:\n(nill)\ntest result:\n");
	stack = stack_init(stack_arr2, 1, 'A');
	print_stack(stack);
	
	//test 3 arr == NULL ale len = 0
	printf("\nTEST 3: arr = NULL, len > 1\n");
	int *stack_arr3 = NULL;
	printf("expected result:\n(nill)\ntest result:\n");
	stack = stack_init(stack_arr3, 0, 'A');
	print_stack(stack);

	//test 4 endless loop test
	printf("\nTEST 4: endless loop test\n");
	int stack_arr4[2] = {1,2};
	stack = stack_init(stack_arr4,2,'A');
	printf("expected result:\n1\ntest result:\n");
	printf("%i\n",stack->head->next->next->value);

	printf("\n\n");
}

// test this separately and run valgrind
void	freetest()
{

	int arra[4] = {1,2,3,4};
	int arrb[2] = {10};
	t_stack *stackA =  stack_init(arra, 4, 'A');
	t_stack *stackB =  stack_init(arrb, 1, 'B');
	t_stack *stackC = create_stack(NULL, 0, 'C');
	free_stack(stackA);
	printf("stackA free'd\n");
	free_stack(stackB);
	printf("stackB free'd\n");
	free_stack(stackC);
	printf("stackC free'd\n");
	printf("run valgrind ./ops_test for memory leaks check!\n");
	
}

void	node_insert_test()
{
	printf("UNIT TEST: node_insert()\n");
	//stack1
	int stack_arr[3] = {1,2,3};
	t_stack *stack = stack_init(stack_arr, 3, 'A');
	printf("input stack: \n");
	print_stack(stack);
	printf("expected result:\n{4, 1, 2, 3}\ntest result:\n");
	t_node *node = create_node(4,NULL,NULL);
	node_insert(stack, node);
	print_stack(stack);
	printf("\n\n");
}

void	push_test()
{
	printf("UNIT TEST: push()\n");
	printf("TEST 1:\n");
	printf("expected result:\n{2,3,4}\n{1,10}\ntest result:\n");
	int arr[4] = {1,2,3,4};
	int arrb[2] = {10};
	t_stack *stackA =  stack_init(arr, 4, 'A');
	t_stack *stackB =  stack_init(arrb, 1, 'B');
	//t_stack *stackB = create_stack(NULL, 0, 'B');
	//printf("init good1\n");
	//printf("%p, %p\n", stackB, stackB);
	push(stackA, stackB);
	print_stack(stackA);
	print_stack(stackB);
	printf("\n");

	//test 2 push from empty stack
	printf("TEST 2:\n");
	printf("expected result:\n{2,3}\n{}\ntest result:\n");
	int arr2[2] = {2,3};
	stackA = stack_init(arr2, 2, 'A');
	stackB = create_stack(NULL,0, 'B');
	push(stackB, stackA);
	print_stack(stackA);
	print_stack(stackB);
	printf("\n");

	//test 3
	printf("TEST 3:\n");
	printf("expected result:\n{3}\n{2}\ntest result:\n");
	push(stackA, stackB);
	print_stack(stackA);
	print_stack(stackB);
	printf("\n");

	//test 4
	printf("TEST 4:\n");
	printf("expected result:\n{}\n{3,2}\ntest result:\n");
	push(stackA, stackB);
	print_stack(stackA);
	print_stack(stackB);
	printf("\n");

	//test 5
	printf("TEST 5:\n");
	printf("expected result:\n{}\n{3,2}\ntest result:\n");
	push(stackA, stackB);
	print_stack(stackA);
	print_stack(stackB);
	printf("\n");
}

void	rotate_test()
{
	printf("\n=====UNIT_TEST: rotate()=====\n");
	printf("--->TEST 1:\ninput stack: {4,1,2,3}\nexpected result after rotation:\nra\n{1,2,3,4}\ntest result:\n");
	int arr1[4] = {4,1,2,3};
	t_stack *stack = stack_init(arr1, 4, 'a');
	rotate(1,stack);
	print_stack(stack);

	//test2
	printf("--->TEST 2:\ninput stack: a = {1,2,3,4}, b= {7,5,6}\nexpected result after rotation:\nrr\n{2,3,4,1}\n{5,6,7}\ntest result:\n");
	int arr2[3] = {7,5,6};
	t_stack *stack2 = stack_init(arr2,3,'b');	
	rotate(2,stack,stack2);
	print_stack(stack);
	print_stack(stack2);
	free_stack(stack);
	free_stack(stack2);

	//test 3, rotation on one element
	printf("--->TEST 3:\ninput stack: a = {1}\nexpected result after rotation:\nrc\n{1}\ntest result:\n");
	int arr3[1] = {1};
	stack = stack_init(arr3, 1, 'c');
	rotate(1,stack);
	print_stack(stack);
	free(stack);

	//test 4, rotation of empty stack
	printf("--->TEST 4:\ninput stack: a = {}\nexpected result after rotation:\n\ntest result:\n");
	stack = create_stack(NULL,0, 'b');
	rotate(1,stack);
	free(stack);
	printf("\n");	
}	

void	rev_rotate_test()
{
	printf("\n=====UNIT_TEST: rev_rotate()=====\n");
	printf("--->TEST 1:\ninput stack: {4,1,2,3}\nexpected result after rotation:\nrra\n{3,4,1,2}\ntest result:\n");
	int arr1[4] = {4,1,2,3};
	t_stack *stack = stack_init(arr1, 4, 'a');
	rev_rotate(1,stack);
	print_stack(stack);

	//test2
	printf("--->TEST 2:\ninput stack: a = {1,2,3,4}, b= {7,5,6}\nexpected result after rotation:\nrrr\n{2,3,4,1}\n{6,7,5}\ntest result:\n");
	int arr2[3] = {7,5,6};
	t_stack *stack2 = stack_init(arr2,3,'b');	
	rev_rotate(2,stack,stack2);
	print_stack(stack);
	print_stack(stack2);
	free_stack(stack);

	//test2.2
	printf("--->TEST 2.2:\ninput stack: b = {6,7,5}\nexpected result after rotation:\nrrb\n{5,6,7}\ntest result:\n");
	rev_rotate(1,stack2);
	print_stack(stack2);
	free_stack(stack2);
	
	//test 3, rotation on one element
	printf("--->TEST 3:\ninput stack: a = {1}\nexpected result after rotation:\nrrc\n{1}\ntest result:\n");
	int arr3[1] = {1};
	stack = stack_init(arr3, 1, 'c');
	rev_rotate(1,stack);
	print_stack(stack);
	free(stack);

	//test 4, rotation of empty stack
	printf("--->TEST 4:\ninput stack: a = {}\nexpected result after rotation:\n\ntest result:\n");
	stack = create_stack(NULL,0, 'b');
	rev_rotate(1,stack);
	free(stack);
	printf("\n");	
}	

void	swap_test()
{
	t_stack	*stackA;
	t_stack	*stackB;

	printf("\n=====UNIT_TEST: swap()=====\n");
	int arr1[3] = {5,7,4};
	stackA = stack_init(arr1,3,'a');
	printf("--->TEST 1:\ninput stack: a = {5,7,4}\n");
	printf("expected result after swap:\nsa\nsa\n{5,7,4}\ntest result:\n");
	swap(1, stackA);
	swap(1, stackA);
	print_stack(stackA);
	
	//test2 - testing ss
	int arr2[3] = {3,4,2};
	stackB = stack_init(arr2,3,'a');
	printf("--->TEST 2:\ninput stack: a = {5,7,4}, b = {3,4,2}\n");
	printf("expected result after swap:\nss\n{7,5,4}\n{4,3,2}test result:\n");
	swap(2, stackA, stackB);
	print_stack(stackA);
	print_stack(stackB);
	free_stack(stackA);
	free_stack(stackB);

	//TEST 3, 
	int arr3[1] = {1};
	stackA = stack_init(arr3,1,'a');
	printf("--->TEST 3:\ninput stack: a = {1}\n");
	printf("expected result after swap:\nsa\n{1}\ntest result:\n");
	swap(1, stackA);
	print_stack(stackA);
	free_stack(stackA);

	//TEST 4, NULL STACK
	stackA = create_stack(NULL, 0, 'a'); 
	printf("--->TEST 3:\ninput stack: a = {}\n");
	printf("expected result after swap:\nsa\n\ntest result:\n");
	swap(1, stackA);
	print_stack(stackA);
	free_stack(stackA);
	printf("\n");
}

//list of test
//stack_init_test = init_test()
//node_insert_test()
//node_retrieve_test()
//push_test;
	

int main()
{
	//parametr for testing:
	int option = 0;

	if (option == 1)
		freetest();
	else
	{
		//init_test();
		//node_retrieve_test();
		//node_insert_test();
		push_test();
		rotate_test();
		rev_rotate_test();
		swap_test();
		return(0);
	}
}
