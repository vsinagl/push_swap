/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middleway.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap_sort(t_stack	*stack)
{
	if (stack->len > 2 || stack->len == 1)
		return ;
	if (stack->head->value > stack->head->next->value)
		swap(1, stack);
	return ;
}

void	push_or_rotate(t_stack *stackA, t_stack *stackB, int *sortedA)
{
	int	i;
	int	index;
	int	median;

	mergesort(sortedA, stackA->len);
	if (stackA->len % 2 == 0)
		index = ((int)(stackA->len) / 2);
	else
		index = ((int)(stackA->len) / 2) + 1;
	median = sortedA[index];
	i = 0;
	while (i < index)
	{
		if (stackA->head->value < median)
		{
			i++;
			push(stackA, stackB);
		}
		else
			rotate(1, stackA);
	}
	free(sortedA);
}

void	middle_sort(t_stack *stackA, t_stack *stackB)
{
	int	*sorted_a;

	sorted_a = NULL;
	sorted_a = int_copy_fromstack(stackA, 0, stackA->len);
	push_or_rotate(stackA, stackB, sorted_a);
	if (stackA->len > 3)
		middle_sort(stackA, stackB);
	else if (stackA->len == 3)
		mini_sort(stackA);
	else
		swap_sort(stackA);
	free(sorted_a);
}

void	six_sort(t_stack *stackA, t_stack *stackB)
{
	if (stackA->len <= 2)
		swap_sort(stackA);
	else if (stackA->len == 3)
		mini_sort(stackA);
	else
	{
		while (stackA->len > 3)
			push(stackA, stackB);
		mini_sort(stackA);
		injection_sort2(stackB, stackA, 0, stackA->head->value);
	}
}

void	middleway(t_stack *stackA, t_stack *stackB)
{
	middle_sort(stackA, stackB);
	injection_sort2(stackB, stackA, 0, stackA->head->value);
}
