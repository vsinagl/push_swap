#include "pushswap.h"

void	rotate_both(stack *p_stackA, stack *p_stackB)
{
	rotate(p_stackA);
	rotate(p_stackB);
	ft_print("rr\n");
}

void	rev_rotate_both(stack *p_stackA, stack *p_stackB)
{
	rev_rotate(p_stackA);
	rev_rotate(p_stackB);
	ft_print("rrr\n");
}

void	pushA(stack *from, stack *to)
{
	if(from->len > 0)
	{
		if (from->head + 1 >= from->len)
			from->head = from->head + 1 - from->len;
		else
			from->head++;


}


