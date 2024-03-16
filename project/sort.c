#include "../pushswap.h"

void	divide(t_stack *stackA, t_stack *stackB, int *dupA, int len)
{
	int		result[3];
	int		i;
	int		j;

	result[0] = dupA[(int)(len/4)];
	result[1] = dupA[(int)(len/2)];
	result[2] = dupA[(int)((len/4) * 3)];
	i = 0;
	j = 0;
	while(i < (len/4) * 3)
	{
		//printf("stackA head: %i\n",stackA->head->value);
		//printf("q1: %i, q2 %i, q3 %i\n",result.q1,result.q2,result.q3);
		//printf("i: %i\n", i);
		while ((stackA->head->value <= result[j]) && (len/4) * 3)
		{
			push(stackA, stackB);
			i++;
		}
		rotate(1, stackA);
		j++;
	}
}

void	divide2(t_stack *stackA, t_stack *stackB, int *dupA, int len)
{
	t_result	result;
	int			i;
	int			q_change;
	int			position;

	result.q1 = dupA[(int)(len/4)];
	result.q2 = dupA[(int)(len/2)];
	result.q3 = dupA[(int)((len/4) * 3)];
	i = 0;
	q_change = 0;
	position = 0;
	push(stackA, stackB);
	while(i < len/2)
	{
		printf("stackA head: %i\n",stackA->head->value);
		printf("q1: %i, q2 %i, q3 %i\n",result.q1,result.q2,result.q3);
		printf("i: %i\n", i);
		while ((stackA->head->value <= result.q1) && (i < len/2))
		{
			while(position > 0 && q_change > 2)
			{
				rotate(1, stackB);
				position--;
			}
			position++;
			push(stackA, stackB);
			i++;
		}
		q_change++;
		while ((stackA->head->value > result.q1) && (stackA->head->value <= result.q2) && (i < len/2))
		{
			while(position > 0 && q_change > 2)
			{
				rotate(1, stackB);
				position--;
			}
			position++;
			push(stackA, stackB);
			i++;
		}
		rotate(1, stackA);
		q_change++;
	}
}
			

void	sort(int *input, size_t len)
{
	t_stack 	*stackA;
	t_stack		*stackB;
	int			*dupA;

	stackA = stack_init(input, len, 'a');
	dupA = int_copy(input, len);
	stackB = stack_init(NULL, 0, 'b');
	mergesort(dupA, len);
	divide(stackA, stackB, dupA, len);
	push(stackB, stackA);
	injection_sort2(stackB, stackA, 0, stackA->head->value);
	//na kvartaly pouze pokud to je vetsi jak 16, jinak bych to nechal na polovic, lze pak otestovat na poctu instrukci
	print_stack(stackA);
	print_stack(stackB);

	
}

		

/*
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
//	print_stack(stackA);
//	ft_printf("\nand stack B: ");
//	print_stack(stackB);
//	ft_printf("\n"); 

	injection_sort2(stackA, stackB, 0, 1);
//	ft_printf("stackA:\n");
	print_stack(stackA);
	ft_printf("stackB:\n");
	print_stack(stackB);
	free_stack(stackA);
	free_stack(stackB);
	int arr[6] = {100, 100 , -123 ,-2 ,1023 ,100};
	int *arr_copy;
	arr_copy = int_copy(arr, 6);
	mergesort(arr_copy, 6);
	for (int i = 0; i < 6; i++)
		printf("%i ", arr_copy[i]);
	printf("\n");
}
*/

