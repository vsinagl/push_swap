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

void	merge(int *arr, int *arr1, int *arr2, int len1, int len2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (j < len2 || i < len1)
	{
		if (len1 > i && (len2 <= j || arr1[i] <= arr2[j]))
		{
			arr[i + j] = arr1[i];
			i++;
		}
		else
		{
			arr[i + j] = arr2[j];
			j++;
		}
	}
}

int	*mergesort(int *arr, int len)
{
	int	len1;
	int	len2;
	int	arr1[1000]; //udelat dynamicky
	int	arr2[1000];

	if (len < 2)
		return (arr);
	len1 = len / 2;
	len2 = len - len1;
	copy_array(arr, arr1, len1);
	copy_array(arr + len1, arr2, len2);
	mergesort(arr1, len1);
	mergesort(arr2, len2);
	merge(arr, arr1, arr2, len1, len2);
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
