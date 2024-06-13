/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		return (0);
	return (1);
}

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

int	main(int argc, char *argv[])
{
	int	*input;

	if (argc <= 1)
		return (1);
	input = process_input(argc, argv);
	if (input == NULL)
	{
		ft_printf("Error");
		return (1);
	}
	merge_sort(input, (argc - 1));
	free(input);
	return (0);
}
