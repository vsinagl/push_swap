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

void	rotation_sequence(t_stack *to, int movedist)
{
	if(movedist > 0)
	{
		while(movedist-- > 0)
		{
			rotate(1, to);
			to->head_i++;
		}
	}
	else if (movedist < 0)
	{
		while(movedist++ < 0)
		{
			rev_rotate(1, to);
			to->head_i--;
		}
	}
	if (to->head_i <= 0)
		to->head_i--;
}


void	rotation_sequence_two(t_stack *to, t_stack *from, t_solver *solver)
{
	if (solver->matrix[0][solver->bi_score] > 0)
	{
		while (solver->matrix[0][solver->bi_score]-- > 0)
		{
			if (solver->matrix[1][solver->bi_score] > 0)
			{
				solver->matrix[1][solver->bi_score]--;
				rotate(2, to, from);
				to->head_i++;
			}
			else
			{
				rotate(1, from);
			}
		}
	}
	else if (solver->matrix[0][solver->bi_score] < 0)
	{
		while (solver->matrix[0][solver->bi_score]++ < 0)
		{
			if (solver->matrix[1][solver->bi_score] < 0)
			{
				solver->matrix[1][solver->bi_score]++; 
				rev_rotate(2, to, from);
				to->head_i--;
			}
			else
			{
				rev_rotate(1, from);
			}
		}
	}
}
	





