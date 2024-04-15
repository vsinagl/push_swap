#include "../pushswap.h"

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

