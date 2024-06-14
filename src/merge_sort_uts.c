/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_uts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort_last_two(t_chunk *ch_to_sort, t_stack *stackA, t_stack *stackB)
{
	if (ch_to_sort->loc == BOT_A)
	{
		rev_rotate(1, stackA);
		rev_rotate(1, stackA);
	}
	else if (ch_to_sort->loc == TOP_B)
	{
		push(stackB, stackA);
		push(stackB, stackA);
	}
	else if (ch_to_sort->loc == BOT_B)
	{
		rev_rotate(1, stackB);
		rev_rotate(1, stackB);
		push(stackB, stackA);
		push(stackB, stackA);
	}
	if (get_stack_value(stackA, 0) > get_stack_value(stackA, 1))
		swap(1, stackA);
	return ;
}

void	sort_last_one(t_chunk *ch_to_sort, t_stack *stackA, t_stack *stackB)
{
	if (ch_to_sort->loc == BOT_A)
	{
		rev_rotate(1, stackA);
	}
	else if (ch_to_sort->loc == TOP_B)
	{
		push(stackB, stackA);
	}
	else if (ch_to_sort->loc == BOT_B)
	{
		rev_rotate(1, stackB);
		push(stackB, stackA);
	}
	return ;
}

void	chose_pivots_calculation(int *sorted_arr, t_chunk *ch_to_sort,
		t_mergestruct *mergestruct)
{
	if (ch_to_sort->loc == TOP_A && ch_to_sort->len > 5)
	{
		mergestruct->border2 = sorted_arr[(ch_to_sort->len / 2)];
		mergestruct->border1 = sorted_arr[((ch_to_sort->len / 4))];
	}
	else if (ch_to_sort->len > 5 && ch_to_sort->loc == BOT_A)
	{
		mergestruct->border2 = sorted_arr[(ch_to_sort->len / 2)];
		mergestruct->border1 = sorted_arr[((ch_to_sort->len / 4))];
	}
	else
	{
		mergestruct->border1 = sorted_arr[ch_to_sort->len / 3];
		mergestruct->border2 = sorted_arr[2 * (ch_to_sort->len / 3)];
	}
}

void	chose_pivots(t_chunk *ch_to_sort, t_stack *stackA,
		t_stack *stackB, t_mergestruct *mergestruct)
{
	int	*intarr;

	intarr = NULL;
	if (ch_to_sort->loc == TOP_A)
		intarr = int_copy_fromstack(stackA, 0, ch_to_sort->len);
	else if (ch_to_sort->loc == TOP_B)
		intarr = int_copy_fromstack(stackB, 0, ch_to_sort->len);
	else if (ch_to_sort->loc == BOT_A)
		intarr = int_copy_fromstack(stackA, (stackA->len - ch_to_sort->len),
				stackA->len);
	else if (ch_to_sort->loc == BOT_B)
		intarr = int_copy_fromstack(stackB, (stackB->len - ch_to_sort->len),
				stackB->len);
	mergesort(intarr, ch_to_sort->len);
	chose_pivots_calculation(intarr, ch_to_sort, mergestruct);
	free(intarr);
}

void	mergestruct_init(t_mergestruct *mergestruct)
{
	mergestruct->border1 = 0;
	mergestruct->border2 = 0;
	mergestruct->min.len = 0;
	mergestruct->mid.len = 0;
	mergestruct->max.len = 0;
}
