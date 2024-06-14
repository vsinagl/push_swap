/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	chunk_locations(t_mergestruct *mergestruct, enum e_loc loc)
{
	if (loc == TOP_A)
	{
		mergestruct->max.loc = BOT_A;
		mergestruct->mid.loc = TOP_B;
		mergestruct->min.loc = BOT_B;
	}
	else if (loc == TOP_B)
	{
		mergestruct->max.loc = TOP_A;
		mergestruct->mid.loc = BOT_A;
		mergestruct->min.loc = BOT_B;
	}
	else if (loc == BOT_B)
	{
		mergestruct->max.loc = TOP_A;
		mergestruct->mid.loc = BOT_A;
		mergestruct->min.loc = TOP_B;
	}
	else
	{
		mergestruct->max.loc = TOP_A;
		mergestruct->mid.loc = TOP_B;
		mergestruct->min.loc = BOT_B;
	}
}

void	split_chunks_min(t_chunk *ch_to_sort, t_mergestruct *mergestruct)
{
	if (ch_to_sort->loc == TOP_A)
	{
		push(mergestruct->from, mergestruct->to);
		rotate(1, mergestruct->to);
	}
	else if (ch_to_sort->loc == TOP_B)
	{
		rotate(1, mergestruct->from);
	}
	else if (ch_to_sort->loc == BOT_B)
	{
		rev_rotate(1, mergestruct->from);
	}
	else
	{
		rev_rotate(1, mergestruct->from);
		push(mergestruct->from, mergestruct->to);
		rotate(1, mergestruct->to);
	}
	mergestruct->min.len += 1;
}

void	split_chunks_mid(t_chunk *ch_to_sort, t_mergestruct *mergestruct)
{
	if (ch_to_sort->loc == TOP_A)
		push(mergestruct->from, mergestruct->to);
	else if (ch_to_sort->loc == TOP_B)
	{
		push(mergestruct->from, mergestruct->to);
		rotate(1, mergestruct->to);
	}
	else if (ch_to_sort->loc == BOT_B)
	{
		rev_rotate(1, mergestruct->from);
		push(mergestruct->from, mergestruct->to);
		rotate(1, mergestruct->to);
	}
	else
	{
		rev_rotate(1, mergestruct->from);
		push(mergestruct->from, mergestruct->to);
	}
	mergestruct->mid.len += 1;
}

void	split_chunks_max(t_chunk *ch_to_sort, t_mergestruct *mergestruct)
{
	if (ch_to_sort->loc == TOP_A)
	{
		rotate(1, mergestruct->from);
	}
	else if (ch_to_sort->loc == TOP_B)
		push(mergestruct->from, mergestruct->to);
	else if (ch_to_sort->loc == BOT_B)
	{
		rev_rotate(1, mergestruct->from);
		push(mergestruct->from, mergestruct->to);
	}
	else
		rev_rotate(1, mergestruct->from);
	mergestruct->max.len += 1;
}

//split_chunks f. make stack operations (rra, ra, ...)
//and divide actual chunk into three(MID, MAX, MIN)
//MIN = lowest values, MAX = maximum values, MID = values between MID and MAX
//split_chunks needs to have initilized mergestruct with border values
//borders(or also pivots) are integers that tells you to
//which chunk should be actual value in stack putted.
//Pivots are produced by chose pivots function
void	split_chunks(t_chunk *ch_to_sort, t_mergestruct *mergestruct)
{
	int	p_index;

	chunk_locations(mergestruct, ch_to_sort->loc);
	p_index = 0;
	while (ch_to_sort->len > 0)
	{
		if (ch_to_sort->loc != TOP_A && ch_to_sort->loc != TOP_B)
			p_index = mergestruct->from->len - 1;
		if (get_stack_value(mergestruct->from, p_index) < mergestruct->border1)
		{
			split_chunks_min(ch_to_sort, mergestruct);
		}
		else if (get_stack_value(mergestruct->from,
				p_index) < mergestruct->border2)
		{
			split_chunks_mid(ch_to_sort, mergestruct);
		}
		else
		{
			split_chunks_max(ch_to_sort, mergestruct);
		}
		ch_to_sort->len--;
	}
}
