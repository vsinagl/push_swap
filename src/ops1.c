/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push(t_stack *from, t_stack *to)
{
	t_node	*node;
	t_node	*head;

	if (from == NULL || to == NULL || from->head == NULL || from->len == 0)
		return ;
	node = create_node(from->head->value, NULL, NULL);
	head = from->head;
	if (from->len > 1)
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		from->head = from->head->next;
	}
	from->len--;
	free(head);
	ft_printf("p%c\n", to->name);
	node_insert(to, node);
}

void	rotate(int numstack, ...)
{
	va_list	args;
	t_stack	*stack;
	int		i;

	if (numstack <= 0)
		return ;
	va_start(args, numstack);
	i = 0;
	while (i < numstack)
	{
		i++;
		stack = va_arg(args, t_stack *);
		if (stack == NULL || stack->len == 1 || stack->head == NULL)
			break ;
		stack->head = stack->head->next;
	}
	if (numstack == 1)
		ft_printf("r%c\n", stack->name);
	else
		ft_printf("rr\n");
	va_end(args);
}

void	rev_rotate(int numstack, ...)
{
	va_list	args;
	t_stack	*stack;
	int		i;

	if (numstack <= 0)
		return ;
	va_start(args, numstack);
	i = 0;
	while (i < numstack)
	{
		i++;
		stack = va_arg(args, t_stack *);
		if (stack == NULL || stack->head == NULL)
			return ;
		if (stack->len == 1)
			break ;
		stack->head = stack->head->prev;
	}
	va_end(args);
	if (numstack == 1)
		ft_printf("rr%c\n", stack->name);
	else
		ft_printf("rrr\n");
}

void	swap_ops(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	node1 = stack->head;
	node2 = stack->head->next;
	if (stack->len > 2)
	{
		node1->prev->next = node2;
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->prev = node1->prev;
		node1->prev = node2;
		node2->next = node1;
	}
	stack->head = node2;
}

void	swap(int numstack, ...)
{
	va_list	args;	
	int		i;
	t_stack	*stack;

	if (numstack <= 0)
		return ;
	va_start(args, numstack);
	i = numstack;
	while (i-- > 0)
	{
		stack = va_arg(args, t_stack *);
		if (stack == NULL || stack->head == NULL)
			return ;
		if (stack->len == 1)
			break ;
		swap_ops(stack);
	}
	va_end(args);
	if (numstack == 1)
		ft_printf("s%c\n", stack->name);
	else
		ft_printf("ss\n");
}
