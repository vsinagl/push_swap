#include "../pushswap.h"

t_node	*create_node(int value, t_node *next, t_node *prev)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->next = next;
	node->prev = prev;
	node->value = value;
	return (node);
}

t_stack	*create_stack(t_node *head, size_t len, char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->head = head;
	stack->len = len;
	stack->name = name;
	stack->head_i = 0;
	return (stack);
}

t_stack	*stack_init(int *arr, size_t len, char name)
{
	size_t	i;
	t_node	*prev;
	t_node	*curr;
	t_stack	*stack;

	if (arr == NULL || len == 0)
		return (NULL);
	i = 0;
	curr = create_node(arr[i], NULL, NULL);
	stack = create_stack(curr, len, name);
	prev = curr;
	while (++i < len)
	{
		curr = create_node(arr[i], NULL, prev);
		prev->next = curr;
		prev = curr;
	}
	curr->next = stack->head;
	stack->head->prev = curr;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*curr;
	t_node	*tmp;

	if (stack == NULL)
		return ;
	if (stack->len > 0)
	{
		curr = stack->head;
		curr->prev->next = NULL;
		while (curr != NULL)
		{
			tmp = curr;
			curr = curr->next;
			free(tmp);
		}
	}
	free(stack);
}

void	node_insert(t_stack *to, t_node *node)
{
	t_node	*head;

	head = to->head;
	if (to->len == 0)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev = head->prev;
		head->prev->next = node;
		node->next = head;
		head->prev = node;
	}
	to->head = node;
	to->len++;
}
