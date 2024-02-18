#include "pushswap.h"

//create a structure that will containt all information about the array. Create functions for operations with this structure. Structure is needed because we will need more arguments in functions that needed.

void	print_stack(stack *p_stack)
{
	size_t	head_i;
	size_t	i;

	i = 0;
	head_i = p_stack->head;
	printf("{");
	while(i < p_stack->len)
	{
		//here should be my printf function!!
		printf("%i", p_stack->self[head_i]);
		if (i < p_stack->len -1)
				printf(", ");
		if (head_i + 1 >= p_stack->len)
			head_i = head_i  + 1 - p_stack->len;
		else
			head_i++;
		i++;
	}
	printf("} ");
}

void	swap(stack *p_stack)
{
	int	tmp;
	size_t	head_next;	

	head_next = 0;
	tmp = p_stack->self[p_stack->head];
	if (p_stack->head + 1 >= p_stack->len)
		head_next = p_stack->head + 1 - p_stack->len;
	else
		head_next = p_stack->head + 1;
	p_stack->self[p_stack->head] = p_stack->self[head_next];
	p_stack->self[head_next] = tmp;
	//ft_printf("s%c\n",p_stack->name);
}


void	swap_both(stack *p_stackA, stack *p_stackB)
{
		swap(p_stackA);
		swap(p_stackB);
		//ft_printf("ss\n);
		
}

void	rotate(stack *p_stack)
{
		if (p_stack->head + 1 >= p_stack->len)
			p_stack->head = p_stack->head + 1 - p_stack->len;
		else
			p_stack->head++;
		//ft_printf("r%c\n",p_stack->name);
}

void	rev_rotate(stack *p_stack)
{
		if ((long int)(p_stack->head - 1) < 0)
		{
			p_stack->head = p_stack->len - 1;
		}
		else
			p_stack->head--;
		//ft_printf("r%c\n",p_stack->name);
}
