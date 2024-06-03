#include "../pushswap.h"

int	*comparsion(t_stack *stack)
{
	size_t	i;
	int		*arr;
	t_node	*nodei;
	
	i = 0;
	arr = (int *)malloc(sizeof(int) * 3);
	nodei = stack->head;
	while (i < stack->len)
	{
		arr[i] = nodei->value <= nodei->next->value;
		i++;
		nodei = nodei->next;
	}
	return(arr);
}


void	mini_sort(t_stack *stack)
{
	int	*arr;

	if (stack->len != 3)
		return ;
	arr = comparsion(stack);
	if (arr[0] == 1 && arr[1] == 1)
		return;
	if ((arr[0] == 0 && arr[1] == 0))
	{
		rotate(1, stack);
		swap(1, stack);
	}
	if (arr[0] == 0 && arr[1] == 1 && arr[2] == 1)
		rotate(1, stack);
	if (arr[0] == 0 && arr[1] == 1 && arr[2] == 0)
		swap(1, stack);
	if (arr[0] == 1 && arr[1] == 0)
	{
		rev_rotate(1, stack);
		if (arr[2] == 0)
			swap(1, stack);
	}
	free(arr);
}


void	injection_sort(t_stack *from, t_stack *to)
{
	int		len;
	int		index;
	int		movedist;

	len = 0;
	while(from->len != 0)
	{
		index = 0;
		if (to->len == 0)
			index = 1;
		while (index < len && (from->head->value < get_stack_value(to, index - to->head_i)))
			index++;
		movedist = rotation_distance(to->len, to->head_i, index, len);
		rotation_sequence(to, movedist);	
		push(from, to);
		to->head_i = index;
		len++;
	}
	movedist = rotation_distance(to->len, to->head_i, 0, len);
	rotation_sequence(to, movedist);	
}

void	recalculate_head(t_stack *stack)
{
	int sign = 1;
	if (stack->head_i == 0)
		return ;
	if (stack->head_i < 0)
		sign = 0;
	int res = ABS(stack->len - ABS(stack->head_i));
	if (res < ABS(stack->head_i))
	{
		if (sign == 1)
			stack->head_i = -res;
		else
			stack->head_i = res;
	}
}

void	injection_sort2(t_stack *from, t_stack *to, int len, int min)
{
	t_solver	*solver;
	int			movedist;

	while(from->len != 0)
	{
		solver = create_solver(from, to, from->head_i, to->head_i);
		rotation_sequence_two(to, from, solver);
		rotation_sequence(to, solver->matrix[1][solver->bi_score]);
		if (from->head->value <= min)
		{
			min = from->head->value;
			to->head_i++;
		}
		push(from, to);
		recalculate_head(to);
	}
	movedist = rotation_distance(to->len, to->head_i, 0, len);
	rotation_sequence(to, movedist);	
}
