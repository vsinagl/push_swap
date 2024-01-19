#include <stdio.h>

int	*injection_sort(int *array, int len)
{
	int j, key;

	for (int i = 1; i < len; i++)
	{
		key = array[i];
		j = i - 1;
		while(j >= 0 && key < array[j])
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
	return(array);
}

int main(void)
{
	int array[8] = {1,2,40,8,4,20,0,3};
	int len = 8;
	int *sorted_arr = injection_sort(array, len);
	printf("array: ");
	for (int i = 0; i < len; i++)
	{
		printf("%i, ", array[i]);
	}
	printf("\n");
	return(0);
}