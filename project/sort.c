#include "../pushswap.h"

int	*comparsion(t_stack *stack)
{
	size_t	i;
	int		*arr;
	t_node	*nodei;
	
	i = 0;
	arr = (int *)malloc(sizeof(int) * 3);
	nodei = stack->head;
	while (i < stack->len)
	{
		arr[i] = nodei->value <= nodei->next->value;
		i++;
		nodei = nodei->next;
	}
	return(arr);
}


void	mini_sort(t_stack *stack)
{
	int	*arr;

	if (stack->len != 3)
		return ;
	arr = comparsion(stack);
	if (arr[0] == 1 && arr[1] == 1)
		return;
	if ((arr[0] == 0 && arr[1] == 0))
	{
		rotate(1, stack);
		swap(1, stack);
	}
	if (arr[0] == 0 && arr[1] == 1 && arr[2] == 1)
		rotate(1, stack);
	if (arr[0] == 0 && arr[1] == 1 && arr[2] == 0)
		swap(1, stack);
	if (arr[0] == 1 && arr[1] == 0)
	{
		rev_rotate(1, stack);
		if (arr[2] == 0)
			swap(1, stack);
	}
	free(arr);
}


void	injection_sort(t_stack *from, t_stack *to)
{
	int		head;
	int		len;
	int		index;
	int		movedist;

	head = 0;
	len = 0;
	while(from->len != 0)
	{
		index = 0;
		if (to->len == 0)
			index = 1;
		while (index < len && (from->head->value < get_stack_value(to, index - head)))
			index++;
		movedist = rotation_distance(to->len, head, index, len);
		rotation_sequence(to, movedist, head);	
		push(from, to);
		head = index;
		len++;
	}
	movedist = rotation_distance(to->len, head, 0, len);
	head = rotation_sequence(to, movedist, head);	
}

//ppo kazdem pushi se bude muset prepocitat hodnoty pro matrix, le to je logicke, musi byt pro to separatni funkce
//matrix si viiniculaziuje na zacatku a jeji velikost bude takova, jako je velikost prvni arraye (respektive celkove array, ta uz se potom nebude menit

void	injection_sort2(t_stack *from, t_stack *to, int len)
{
	int			head_from;
	int			head_to;
	t_solver	*solver;
	int			movedist;

	head_from = 0;
	head_to = 0;
	while(from->len != 0)
	{
		solver = create_solver(from, to, head_from, head_to);
	//	ft_printf("solver results: bi_score: %i\n", solver->bi_score);
	//	ft_printf("solver movedist1: %i", solver->matrix[0][solver->bi_score]);
	//	ft_printf("\tsolver movedist2: %i\n", solver->matrix[1][solver->bi_score]);
	//	ft_printf("movements and results of movements\n\n");
	for (int h = 0; h < solver->matrix_len; h++)
	{
		ft_printf("matrix[0][%i]: %i\n matrix[1][%i]: %i\n, matrix[2][%i]: %i\n",h, solver->matrix[0][h],h, solver->matrix[1][h],h, solver->matrix[2][h]);
			
	}
		ft_printf("movements:\n");
		head_from = rotation_sequence_two(from, to, solver, head_from);
//		if (head != solver->bi_score)
//			ft_printf("head != bi_score (%i != %i)\n",head, solver->bi_score);
	//	ft_printf("zbyvajici movedist1: %i", solver->matrix[0][solver->bi_score]);
	//	ft_printf("\tzbyvajici movedist2: %i\n", solver->matrix[1][solver->bi_score]);
		head_to = rotation_sequence(to, solver->matrix[1][solver->bi_score], head_to);
		if (get_stack_value(from,0) > get_stack_value(to, head_to))
			head_to--;
		push(from, to);
		print_stack(from);
		ft_printf("and stack B: ");
		print_stack(to);
		ft_printf("headache: headA = %i, headB = %i\n",head_from, head_to);

		ft_printf("\n");
	}
	ft_printf("\nROLL BACK !!");
	movedist = rotation_distance(to->len, head_to, 0, len);
	rotation_sequence(to, movedist, head_to);	
}

//void	sort(int *input, size_t len)
//{
//	t_stack		*stackA;
//	t_stack		*stackB;
//
//	stackA = stack_init(input, len, 'a');
//	stackB = create_stack(NULL, 0, 'b');
//	injection_sort(stackA, stackB);
//	ft_printf("stackA:\n");
//	print_stack(stackA);
//	ft_printf("stackB:\n");
//	print_stack(stackB);
//	free_stack(stackA);
//	free_stack(stackB);
//}
//
void	sort(int *input, size_t len)
{
	t_stack		*stackA;
	t_stack		*stackB;

	//int arr[3] = {33, 33, 33};
	//vygeneruji cislo 10
	// --> pro 10 budu potrebovat pa, 3xra
	stackA = stack_init(input, len, 'a');
	int b[10] = {1,4,8,11, 12, 20, 40, 80, 90, 100};
 	stackB = stack_init(b, 10, 'b');
	print_stack(stackA);
	ft_printf("\nand stack B: ");
	print_stack(stackB);
	ft_printf("\n"); 

	injection_sort2(stackA, stackB, 0);
	ft_printf("stackA:\n");
	print_stack(stackA);
	ft_printf("stackB:\n");
	print_stack(stackB);
	free_stack(stackA);
	free_stack(stackB);
}


