/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line_bonus.h"
#include <unistd.h>

int	is_duplicate(int *arr, int len, char *arg)
{
	int		number;
	int		i;

	number = ft_atoi(arg);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	i = 0;
	while (i < len)
	{
		if (arr[i] == number)
			return (1);
		i++;
	}
	return (0);
}

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
		return (0);
	return (1);
}

int	*process_input(int argc, char *argv[], int option)
{
	int		*arr;
	int		i;
	int		j;

	i = 0;
	j = 1 - option;
	arr = (int *)malloc(sizeof(int) *(argc - 1));
	while (argv[j] != NULL)
	{
		if (is_int_number(argv[j]) == 0 || is_duplicate(arr, i, argv[j]) == 1)
		{
			free(arr);
			return (NULL);
		}
		arr[i] = (int)ft_atoi(argv[j]);
		i++;
		j++;
	}
	return (arr);
}

//1 == stack ok, 0 = stack ko
int	is_stack_sorted(t_stack *stack)
{
	unsigned int		j;

	j = 0;
	while(j < (stack->len - 1))
	{
		if (get_stack_value(stack, j) > get_stack_value(stack, (j + 1)))
			return 0;
		j++;
	}
	return 1;
}

int	check_inputs(int *input, int len)
{
	char *instruction;
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = stack_init(input, len, 'a');
	stackb = stack_init(NULL, 0, 'b');
	instruction = get_next_line(STDIN_FILENO);
	while(instruction != NULL)
	{
		//zde napsat vlastni str_cmp  a pridat do knihovny!!!
		printf(">%s", instruction);
		if (strcmp(instruction, "sa\n") == 0)
			swap(1,stacka);
		else if (strcmp(instruction, "sb\n") == 0)
			swap(1, stackb);
		else if (strcmp(instruction, "ss\n") == 0)
			swap(2, stackb, stacka);
		else if (strcmp(instruction, "ra\n") == 0)
			rotate(1, stacka);
		else if (strcmp(instruction, "rb\n") == 0)
			rotate(1, stackb);
		else if (strcmp(instruction, "rr\n") == 0)
			rotate(2, stackb, stacka);
		else if (strcmp(instruction, "rra\n") == 0)
			rev_rotate(1, stacka);
		else if (strcmp(instruction, "rrb\n") == 0)
			rev_rotate(1, stackb);
		else if (strcmp(instruction, "rrr\n") == 0)
			rev_rotate(2, stackb, stacka);
		else if (strcmp(instruction, "pa\n") == 0)
			push(stackb, stacka);
		else if (strcmp(instruction, "pb\n") == 0)
			push(stacka, stackb);
		else
			return 0;
		instruction = get_next_line(STDIN_FILENO);
	}
	return (is_stack_sorted(stacka));
}


int	main(int argc, char **argv)
{
	int	*input;

	input = NULL;
	if (argc <= 1)
	{
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = 1;
		while (argv[argc - 1] != NULL)
			argc++;
		input = process_input(argc, argv, 1);
	}
	else if (argc > 2)
	{
		input = process_input(argc, argv, 0);
	}
	if (check_inputs(input, (argc - 1)) == 0)
		ft_printf(RED "KO" RESET);
	else
		ft_printf(GREEN "OK" RESET);
	return 0;
}
