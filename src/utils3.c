/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsinagl <vsinagl@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 09:12:15 by vsinagl           #+#    #+#             */
/*   Updated: 2024/06/13 17:17:31 by vsinagl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	*int_copy_fromstack(t_stack *stack, int i, int len)
{
	int		*res;
	int		j;

	if (stack == NULL)
		return (NULL);
	res = (int *)malloc(sizeof(int) * len);
	if (res == NULL)
		return (NULL);
	j = 0;
	while (i < len)
	{
		res[j] = get_stack_value(stack, i);
		i++;
		j++;
	}
	return (res);
}

void	copy_array(int *src, int *dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
}

void	merge(int *arr, t_array *arr1, t_array *arr2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < arr2->len || i < arr1->len)
	{
		if (arr1->len > i && (arr2->len <= j || arr1->arr[i] <= arr2->arr[j]))
		{
			arr[i + j] = arr1->arr[i];
			i++;
		}
		else
		{
			arr[i + j] = arr2->arr[j];
			j++;
		}
	}
}

int	*mergesort(int *arr, int len)
{
	t_array	arr1;
	t_array	arr2;

	if (len < 2)
		return (arr);
	arr1.len = len / 2;
	arr2.len = len - arr1.len;
	arr1.arr = (int *)malloc(sizeof(int) * arr1.len);
	arr2.arr = (int *)malloc(sizeof(int) * arr2.len);
	copy_array(arr, arr1.arr, arr1.len);
	copy_array(arr + arr1.len, arr2.arr, arr2.len);
	mergesort(arr1.arr, arr1.len);
	mergesort(arr2.arr, arr2.len);
	merge(arr, &arr1, &arr2);
	free(arr1.arr);
	free(arr2.arr);
	return (arr);
}

int	*int_copy(int *arr, int len)
{
	int	*res;
	int	i;

	res = (int *)malloc(len * sizeof(int));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = arr[i];
		i++;
	}
	return (res);
}
