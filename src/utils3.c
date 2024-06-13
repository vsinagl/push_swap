#include "../pushswap.h"

#include <stdlib.h>

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
	int	i, j;

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
	int	len1, len2;
	int	arr1[1000];
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
	return(arr);
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
/*

int* merge(int* arr, int len1, int len2)
{
    int i;
    int	j;
    int *arr1;
    int *arr2;
    
    arr1 = int_copy(arr, len1);
	arr2 = int_copy(arr + len1, len2);
	if (arr1 == NULL || arr2 == NULL)
		return(NULL);
    i = 0;
    j = 0;
    while (j < len2 || i < len1) {
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
    free(arr1);
    free(arr2);
    return arr;
}

int	*mergesort(int* arr, int len)
{
    int len1;
    int	len2;

    if (len == 1)
        return arr;
    len1 = len / 2;
    len2 = len - len1;
    mergesort(arr, len1);
    mergesort(arr + len1, len2);
    merge(arr, len1, len2);
    return arr;
}
*/

