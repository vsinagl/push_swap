#include "../pushswap.h"

int		check_stack(t_stack *stack)
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

void	swap_sort2(t_stack	*stack)
{
	if (stack->len > 2 || stack->len == 1)
		return;
	if (stack->head->value > stack->head->next->value)
		swap(1, stack);
	return;
}

void	six_sort2(t_stack *stackA, t_stack *stackB)
{
	if (stackA->len <= 2)
		swap_sort2(stackA);
	else if (stackA->len == 3)
		mini_sort(stackA);
	else
	{
		while(stackA->len > 3)
			push(stackA, stackB);
		mini_sort(stackA);
		injection_sort2(stackB, stackA, 0, stackA->head->value);
	}
}

void	sort_last_two(t_chunk *ch_to_sort, t_stack *stackA, t_stack *stackB)
{
	if (ch_to_sort->loc == BOT_A)
	{
		rev_rotate(1,stackA);
		rev_rotate(1,stackA);
	}
	else if (ch_to_sort->loc == TOP_B)
	{
		push(stackB, stackA);
		push(stackB, stackA);
	}
	//zde by to slo optimalizovat, napr pokud udelam rev_rot push rev_rot push nebo 2x_rev_rot a pak 2xpush, poradi prvku na TOP_A bude obracene. Vyhnul bych se naslednemu swapu pri stejnem poctu operaci
	else if (ch_to_sort->loc == BOT_B)
	{
		rev_rotate(1, stackB);
		rev_rotate(1, stackB);
		push(stackB, stackA);
		push(stackB, stackA);
	}
	if (get_stack_value(stackA, 0) > get_stack_value(stackA, 1))
		swap(1, stackA);
	return;
}

void	chose_pivots(t_chunk *ch_to_sort, t_stack *stackA,
		t_stack *stackB, t_mergestruct *mergestruct)
{
	int	*intarr;

	if (ch_to_sort->loc == TOP_A)
	{
		intarr = int_copy_fromStack(stackA, 0, ch_to_sort->len);
		mergesort(intarr, ch_to_sort->len);
	}
	else if (ch_to_sort->loc == TOP_B)
	{
		intarr = int_copy_fromStack(stackB, 0, ch_to_sort->len);
		mergesort(intarr, ch_to_sort->len);
	}
	else if(ch_to_sort->loc == BOT_A)
	{
		intarr = int_copy_fromStack(stackA, (stackA->len - ch_to_sort->len),
					stackA->len);
		mergesort(intarr, ch_to_sort->len);
	}
	else if(ch_to_sort->loc == BOT_B)
	{
		intarr = int_copy_fromStack(stackB, (stackB->len - ch_to_sort->len),
					stackB->len);
		mergesort(intarr, ch_to_sort->len);
	}
	mergestruct->border1 = intarr[ch_to_sort->len / 3];
	mergestruct->border2 = intarr[2*(ch_to_sort->len / 3)];
}

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

void	split_chunks(t_chunk *ch_to_sort, t_mergestruct *mergestruct)
{
	int	p_index;
	int	inc;

	chunk_locations(mergestruct, ch_to_sort->loc);
	if (ch_to_sort->loc == TOP_A || ch_to_sort->loc == TOP_B)
	{
		p_index = 0;
		inc = +1;
	}
	else
	{
		p_index = mergestruct->from->len;
		inc = -1;
	}
	printf("chunk loc: %i\n", ch_to_sort->loc);
	while (ch_to_sort->len > 0)
	{
		//do condition je taky treba pridat informace o chunku max, min, mid, zejmena pridat location(napr pro prvni if hnedka dole, kdy ch_to__sort->loc== TOP_A to bude BOT_A !), potom je treba ake postupne incrementovat jeho delku podle toho kolik prvku do nej nasypu!!
		//situace pro max
		printf("stackValue: %i\n", get_stack_value(mergestruct->from, p_index));
		//situace pro min
		if (get_stack_value(mergestruct->from, p_index) < mergestruct->border1)
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
			mergestruct->max.len += 1;
		}
		//situace pro mid
		else if (get_stack_value(mergestruct->from, p_index) < mergestruct->border2)
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
		//situace pro max
		else
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
			mergestruct->min.len += 1;
		}
		ch_to_sort->len--;
		//p_index += inc;
	}
}

void	mergestruct_init(t_mergestruct *mergestruct)
{
	mergestruct->border1 = 0;
	mergestruct->border2 = 0;
	mergestruct->min.len = 0;
	mergestruct->mid.len = 0;
	mergestruct->max.len = 0;
}

void	merge_sort_rec(t_chunk *ch_to_sort,t_stack *stackA, t_stack *stackB)
{
	t_mergestruct mergestruct;
	//in merge struct there are included the pivots value that are used to determine to which chunk the value (index, node) should be moved
	
	printf("++++-----------++++\nEntry chunk info:\nChunk size:\t%i\nChunk loc:\t%i\n", ch_to_sort->len, ch_to_sort->loc);
	mergestruct_init(&mergestruct);
	if (ch_to_sort->loc == TOP_A || ch_to_sort->loc == BOT_A)
	{
		mergestruct.from = stackA;
		mergestruct.to = stackB;
	}
	else
	{
		mergestruct.from = stackB;
		mergestruct.to = stackA;
	}
	if (ch_to_sort->loc == BOT_A && ch_to_sort->len == (int)stackA->len)
		ch_to_sort->loc = TOP_A;
	else if (ch_to_sort->loc == BOT_B && ch_to_sort->len == (int)stackB->len)
		ch_to_sort->loc = TOP_B;
	//base case !!
	if (ch_to_sort->len <= 2)
		sort_last_two(ch_to_sort, stackA, stackB);
	chose_pivots(ch_to_sort, stackA, stackB, &mergestruct);
	printf("pivot1: %i, pivot2: %i\n", mergestruct.border1, mergestruct.border2);
	split_chunks(ch_to_sort, &mergestruct);
	merge_sort_rec(&mergestruct.max, stackA, stackB);
	merge_sort_rec(&mergestruct.mid, stackA, stackB);
	merge_sort_rec(&mergestruct.min, stackA, stackB);
	printf("merge_sort_rec done\n");
	return;
}

void	merge_sort(int *input, size_t len)
{
	t_stack	*stackA;
	t_stack *stackB;
	t_chunk	start_chunk;

	stackA = stack_init(input, len, 'a');
	stackB = stack_init(NULL, 0, 'b');
	start_chunk.loc = TOP_A;
	start_chunk.len = stackA->len;
	//podminky podle delky stackAlen
	if (check_stack(stackA) == 1)
	{
		free_stack(stackA);
		free_stack(stackB);
		return ;
	}
	if(stackA->len <= 5)
		six_sort2(stackA, stackB);
	merge_sort_rec(&start_chunk, stackA, stackB);
	//here will be code for othe
	print_stack(stackA);
	print_stack(stackB);




}
