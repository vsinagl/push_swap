/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	check_stack(t_stack *stack)
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

void	what_stack_iam_pointing_to(t_chunk *ch_to_sort,
		t_mergestruct *mergestruct, t_stack *stackA, t_stack *stackB)
{
	if (ch_to_sort->loc == TOP_A || ch_to_sort->loc == BOT_A)
	{
		mergestruct->from = stackA;
		mergestruct->to = stackB;
	}
	else
	{
		mergestruct->from = stackB;
		mergestruct->to = stackA;
	}
}

//main recursive three-way merge sort function
void	merge_sort_rec(t_chunk *ch_to_sort, t_stack *stackA, t_stack *stackB)
{
	t_mergestruct	mergestruct;

	mergestruct_init(&mergestruct);
	what_stack_iam_pointing_to(ch_to_sort, &mergestruct, stackA, stackB);
	if (ch_to_sort->loc == BOT_A && ch_to_sort->len == (int)stackA->len)
		ch_to_sort->loc = TOP_A;
	else if (ch_to_sort->loc == BOT_B && ch_to_sort->len == (int)stackB->len)
		ch_to_sort->loc = TOP_B;
	if (ch_to_sort->len <= 2)
	{
		if (ch_to_sort->len == 2)
			sort_last_two(ch_to_sort, stackA, stackB);
		else
			sort_last_one(ch_to_sort, stackA, stackB);
		return ;
	}
	chose_pivots(ch_to_sort, stackA, stackB, &mergestruct);
	split_chunks(ch_to_sort, &mergestruct);
	merge_sort_rec(&mergestruct.max, stackA, stackB);
	merge_sort_rec(&mergestruct.mid, stackA, stackB);
	merge_sort_rec(&mergestruct.min, stackA, stackB);
	return ;
}

void	sort_three(t_stack *stackA)
{
	if (stackA->len == 2 && (
			get_stack_value(stackA, 0) > get_stack_value(stackA, 1)))
		swap(1, stackA);
	else if (stackA->len == 3)
		mini_sort(stackA);
	return ;
}

void	merge_sort(int *input, size_t len)
{
	t_stack	*stacka;
	t_stack	*stackb;
	t_chunk	start_chunk;

	stacka = stack_init(input, len, 'a');
	stackb = stack_init(NULL, 0, 'b');
	start_chunk.loc = TOP_A;
	start_chunk.len = stacka->len;
	if (check_stack(stacka) == 1)
	{
		free_stack(stacka);
		free_stack(stackb);
		return ;
	}
	if (stacka->len <= 3)
		sort_three(stacka);
	else if (stacka->len <= 12)
		six_sort(stacka, stackb);
	else
		merge_sort_rec(&start_chunk, stacka, stackb);
	free_stack(stacka);
	free_stack(stackb);
}
