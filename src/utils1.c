/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

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
	if (movedist > 0)
	{
		while (movedist-- > 0)
		{
			rotate(1, to);
			to->head_i++;
		}
	}
	else if (movedist < 0)
	{
		while (movedist++ < 0)
		{
			rev_rotate(1, to);
			to->head_i--;
		}
	}
	if (to->head_i <= 0)
		to->head_i--;
}

void	do_rotations(t_stack *to, t_stack *from, t_solver *solver)
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

void	do_rev_rotations(t_stack *to, t_stack *from, t_solver *solver)
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

void	rotation_sequence_two(t_stack *to, t_stack *from, t_solver *solver)
{
	if (solver->matrix[0][solver->bi_score] > 0)
		do_rotations(to, from, solver);
	else if (solver->matrix[0][solver->bi_score] < 0)
		do_rev_rotations(to, from, solver);
}
