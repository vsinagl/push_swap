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
int	*int_copy_fromStack(t_stack *stack)
{
	int			*res;
	size_t		i;

	if (stack == NULL)
		return(NULL);
	res = (int *)malloc(sizeof(int) * stack->len);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < stack->len)
	{
		res[i] = get_stack_value(stack, i);
		i++;
	}
	return (res);
}

void	middle_sort(t_stack *stackA, t_stack *stackB)
{
	int	median;
	int	*sortedA;
	int	i;
	int	index;

	sortedA = int_copy_fromStack(stackA);
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

void	middleway(int *input, size_t len)
{
	t_stack	*stackA;
	t_stack *stackB;

	//ft_printf("running middleway sort..\n");
	stackA = stack_init(input, len, 'a');
	stackB = stack_init(NULL, 0, 'b');
	//podminky podle delky stackAlen
	while(stackA->len > 3)
	{
		middle_sort(stackA, stackB);//here will be middle sort,
	}
//	print_stack(stackA);
//	print_stack(stackB);
	if (stackA->len == 3)
		mini_sort(stackA);	
	else
		swap_sort(stackA);
//	printf("now injection_sort2:\n");
	injection_sort2(stackB, stackA, 0, stackA->head->value);
//	print_stack(stackA);
//	print_stack(stackB);
}


