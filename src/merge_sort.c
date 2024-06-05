#include "../pushswap.h"

int		check_stack(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (get_stack_value(stack, i) > get_stack_value(stack, i + 1))
			return (0);
		i++;
	}
	return (1);
}

void	swap_sort2(t_stack	*stack)
{
	if (stack->len > 2 || stack->len == 1)
		return;
	if (stack->head->value > stack->head->next->value)
		swap(1, stack);
	return;
}

void	six_sort2(t_stack *stackA, t_stack *stackB)
{
	if (stackA->len <= 2)
		swap_sort2(stackA);
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

void	merge_sort_rec(t_chunk *ch_to_sort,t_stack *from, t_stack *to)
{
	int	p_index;
	int inc;
	t_mergestruct mergestruct;

}

void	merge_sort(int *input, size_t len)
{
	t_stack	*stackA;
	t_stack *stackB;
	t_chunk	start_chunk;

	stackA = stack_init(input, len, 'a');
	stackB = stack_init(NULL, 0, 'b');
	start_chunk.loc = TOP_A;
	start_chunk.len = stackA->len;
	//podminky podle delky stackAlen
	if (check_stack(stackA) == 1)
	{
		free_stack(stackA);
		free_stack(stackB);
		return ;
	}
	if(stackA->len <= 5)
		six_sort2(stackA, stackB);
	merge_sort_rec(&start_chunk, stackA, stackB);
	//here will be code for othe
	print_stack(stackA);
	print_stack(stackB);




}
