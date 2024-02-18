#include "../pushswap.h"

void	print_stack(t_stack *stack)
{
	size_t	i;
	t_node	*node_i;

	if (stack == NULL)
	{
		ft_printf("(nill)\n");
		return ;
	}
	if (stack->head == NULL || stack->len == 0)
	{
		ft_printf("{}\n");
		return ;
	}
	i = 0;
	node_i = stack->head;
	ft_printf("{");
	while(i < stack->len)
	{
		ft_printf("%i",node_i->value);
		if (i < stack->len - 1)
			ft_printf(",");
		else
			ft_printf("}\n");
		i++;
		node_i = node_i->next;
	}
}

