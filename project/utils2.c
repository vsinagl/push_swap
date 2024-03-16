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

void	free_solver(t_solver *solver)
{
	free(solver->matrix[0]);
	free(solver->matrix[1]);
	free(solver->matrix[2]);
	free(solver);
}

t_solver	*init_solver(size_t len)
{
	t_solver	*solver;
	int			i;

	solver = (t_solver*)malloc(sizeof(t_solver));
	if(solver == NULL)
		return(NULL);
	solver->matrix_len = len;
	solver->bi_score = 0;
	i = 0;
	while (i < 3)
	{
		solver->matrix[i] = (int*)malloc(len * sizeof(int));
		i++;
	}
	return(solver);
}

t_solver	*create_solver(t_stack *from, t_stack *to, int head_from, int head_to)
{
	t_solver	*solver;
	int			i;
	int			b_score;

	solver = init_solver(from->len);
	if(solver == NULL)
		return(NULL);
	i = 0;
	b_score = INT_MAX;
	while(i < solver->matrix_len)
	{
		
		solver->matrix[0][i] = rotation_distance((int)(from->len), head_from, i, (int)(from->len));
		solver->matrix[1][i] = get_index(get_stack_value(from, i), to, head_to);
		solver->matrix[2][i] = ABS(solver->matrix[0][i] - solver->matrix[1][i]);
		if (solver->matrix[2][i] < b_score)
		{
			b_score = solver->matrix[2][i];
			solver->bi_score = i;
		}
		i++;
	}
	return(solver);
}
	
	


