#include "../pushswap.h"


int	get_stack_value(t_stack *stack, int index)
{
	t_node	*iternode;
	
	iternode = stack->head;
	if (index <= 0)
	{
		while (index < 0)
		{
			iternode = iternode->prev;
			index++;
		}
		return(iternode->value);
	}
	else
	{
		while (index > 0)
		{
			iternode = iternode->next;
			index--;
		}
		return(iternode->value);
	}
}

int	get_index(int from_head, t_stack *to, int head)
{
	int	index;
	int	movedist;

	index = 0;
	if ((int)(to->len) == 0)
		index = 1;
	while (index < (int)(to->len) && (from_head > get_stack_value(to, index - head)))
		index++;
	movedist = rotation_distance(to->len, head, index, (int)(to->len));
	return(movedist);
}

int	rotation_distance(int stacklen, int head, int index, int len)
{
	int		rr_distance;
	int		r_distance;


	if (index == len && stacklen == len)
		index = 0;
	if (index == head)
		return (0);
	if (head > index)
	{
		rr_distance = head - index;
		r_distance = stacklen - (head - index);
	}
	else
	{
		rr_distance = stacklen - (index - head);
		r_distance = index - head;
	}
	if (r_distance <= rr_distance)
		return (r_distance);
	else
		return (-1 * rr_distance);
}

int	rotation_sequence(t_stack *to, int movedist, int head)
{
	if(movedist > 0)
	{
		while(movedist-- > 0)
		{
			rotate(1, to);
			head++;
		}
	}
	else if (movedist < 0)
	{
		while(movedist++ < 0)
		{
			rev_rotate(1, to);
			head--;
		}
		head--;
	}
	return (head);
}

int	rotation_sequence_two(t_stack *to, t_stack *from, t_solver *solver, int head)
{
	int *movedist1;
	int *movedist2;

	//rewrite the solver structure instead of arrays there wil be just integers movedist1 and movedist2?
	movedist1 = &solver->matrix[0][solver->bi_score];
	movedist2 = &solver->matrix[1][solver->bi_score];
	if (*movedist1 > 0)
	{
		while (*movedist1-- > 0)
		{
			if (*movedist2 > 0)
			{
				while (*movedist2-- > 0)
				{
					rotate(2, to, from);
					head++;
				}
			}
			else
				rotate(1, to);
		}
	}
	else if (*movedist1 < 0)
	{
		while (*movedist1++ < 0)
		{
			if (*movedist2 < 0)
			{
				while (*movedist2++ < 0)
				{
					rev_rotate(2, to, from);
					head--;
				}
			}
			else
				rev_rotate(1, to);
			// head = head - 1; ANO nebo NE?
		}
	}
	return (head);
}
	





