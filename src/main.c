#include "../pushswap.h"

int	is_int_number(const char *str)
{
	long		number;
	const char	*str_org;

	str_org = str;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	number = ft_atoi(str_org);
	if (number > INT_MAX || number < INT_MIN)
		return 0;
	return 1;
}

int	is_duplicate(int *arr, int len, char *arg)
{
	int		number;
	int		i;

	number = ft_atoi(arg);
	if (number > INT_MAX || number < INT_MIN)
		return 0;
	i = 0;
	while ( i < len)
	{
		if (arr[i] == number)
			return 1;
		i++;
	}
	return 0;
}

int	*process_input(int argc, char *argv[])
{
	int		*arr;
	int		i;
	int		j;

	i = 0;
	j = 1;
	arr = (int *)malloc(sizeof(int) *(argc - 1));
	while (i < argc - 1)
	{
		if (is_int_number(argv[j]) == 0  || is_duplicate(arr, i, argv[j]) == 1)
		{
			free(arr);
			return (NULL);
		}
		arr[i] = (int)ft_atoi(argv[j]);
		i++;
		j++;
	}
	return(arr);
}

/*
int	main(int argc, char *argv[])
{
	int	*input;

	if (argc <= 1)
		return 1;
	input = process_input(argc, argv);
	if (input == NULL)
	{
		ft_printf("Error");
		return (1);
	}
	size_t len = (size_t)argc;	
	t_stack *stackA = stack_init(input, len - 1, 'a');
	print_stack(stackA);
	int test = get_stack_value(stackA, 0);
	int test2 = get_stack_value(stackA, 3);
	int test3 = get_stack_value(stackA, -100);
	print_stack(stackA);
	free_stack(stackA);
	printf("the get_stack_value is: %i\n", test);
	printf("the get_stack_value is: %i\n", test2);
	printf("the get_stack_value is: %i\n", test3);
	return(0);
}
*/
	
		
//int	main(int argc, char *argv[])
//{
//	int	*input;
//
//	if (argc <= 1)
//		return 1;
//	input = process_input(argc, argv);
//	if (input == NULL)
//	{
//		ft_printf("Error\n");
//		return (1);
//	}
//
//	//creation of stack
//	size_t len = (size_t)argc;	
//	int b[10] = {1,4,8,11, 12, 20, 40, 80, 90, 100};
//	t_stack *stackA = stack_init(input, len - 1, 'a');
//	t_stack *stackB = stack_init(b, 10, 'b');
//	ft_printf("the created stack is: ");
//	print_stack(stackA);
//	ft_printf("\nand stack B: ");
//	print_stack(stackB);
//	ft_printf("\n"); 
//
//	//verification of distance calculations
//	t_solver *solver;
//	solver = create_solver(stackA, stackB);
//	for(int i = 0; i < (int)(stackA->len); i++)
//	{	
//		ft_printf("element A{%i} = %i", i, get_stack_value(stackA,i));
//		ft_printf("\tdistance top A: %i\n", solver->matrix[0][i]);
//		ft_printf("\tdistance top B: %i\n", solver->matrix[1][i]);
//		ft_printf("\tscore: %i\n", solver->matrix[2][i]);
//	}
//	ft_printf("the chosen index with best score: %i\n", solver->bi_score);
//	free_solver(solver);
//	return(0);
//}
//


int	main(int argc, char *argv[])
{
	int	*input;

	if (argc <= 1)
		return 1;
	input = process_input(argc, argv);
	if (input == NULL)
	{
		ft_printf("Error");
		return (1);
	}
	merge_sort(input, (argc - 1));
	free(input);
	return(0);
}

