#include "../pushswap.h"

//middleway_utils1.c
void	swap_sort(t_stack	*stack)
{
	if (stack->len > 2 || stack->len == 1)
		return;
	if (stack->head->value > stack->head->next->value)
		swap(1, stack);
	return;
}
int	*int_copy_fromStack(t_stack *stack, int i, int len)
{
	int			*res;

	if (stack == NULL)
		return(NULL);
	res = (int *)malloc(sizeof(int) * len);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = get_stack_value(stack, i);
		i++;
	}
	return (res);
}
/*
void	push_or_rotate(t_stack *stackA, t_stack *stackB, int *sortedA)
{
	int	i;
	int	index;
	int median;

	mergesort(sortedA, stackA->len);
	if (stackA->len % 2 == 0)
		index = ((int)(stackA->len) / 2);
	else
		index = ((int)(stackA->len) / 2) + 1;
	median = sortedA[index];
	i = 0;
	while(i < index)
	{
		if (stackA->head->value < median) {
			i++;
			push(stackA, stackB);
		}
		else
			rotate(1,stackA);
	}
	free(sortedA);
}

void	middle_sort(t_stack *stackA, t_stack *stackB)
{
	int	*sortedA;

	sortedA = NULL;
	sortedA = int_copy_fromStack(stackA);
	push_or_rotate(stackA, stackB, sortedA);
	if (stackA->len > 3)
		middle_sort(stackA, stackB);
	else if (stackA->len == 3)
		mini_sort(stackA);	
	else
		swap_sort(stackA);
	free(sortedA);
}

void	six_sort(t_stack *stackA, t_stack *stackB)
{
	if (stackA->len <= 2)
		swap_sort(stackA);
	else if (stackA->len == 3)
		mini_sort(stackA);
	else
	{
		while(stackA->len > 3)
			push(stackA, stackB);
		mini_sort(stackA);
		injection_sort2(stackB, stackA, 0, stackA->head->value);
	}
}



void	middleway(int *input, size_t len)
{
	t_stack	*stackA;
	t_stack *stackB;

	//ft_printf("running middleway sort..\n");
	stackA = stack_init(input, len, 'a');
	stackB = stack_init(NULL, 0, 'b');
	//podminky podle delky stackAlen
	if(stackA->len <= 5)
		six_sort(stackA, stackB);
	else
	{
		middle_sort(stackA, stackB);//here will be middle sort,
		injection_sort2(stackB, stackA, 0, stackA->head->value);
	}
	print_stack(stackA);
	print_stack(stackB);
}

*/
