#include "mergesort_t.h"


int	*rand_array(int size)
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * size);
    // Initialize random number generator
    srand(time(NULL));
    // Fill the array with random integers
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }
	return(arr);
}

int	*arr_copy(int *arr_to_copy, int size)
{
	int *copy;

	copy = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i <= size; i++)
	{
		copy[i] = arr_to_copy[i];
	}
	return(copy);
}

int verify(int *arr, int size)
{
	for (int i = 0; i < (size - 1); i++)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

int main(void)
{
	//TEST DEFINITONS
	int test1[4][5] = {
		{1, -2,  -5, -4, 10 },
		{1,  2, 3, 4, 5},
		{INT_MAX, 0, INT_MIN, 4, 5},
		{10, 9, 8, 7, 6},
	};
	int *test2, *test3, *test4;
	test2 = rand_array(100);
	test3 = rand_array(1000);
	int len4 = 5000;
	test4 = rand_array(len4);

	printf("\n++++++------------------++++++\n");
	printf(RED "\tMERGESORT_UNIT_TEST\n" RESET);
	printf(CYAN "Test1: (4 arrays, each of 5 elements)\n" RESET);
	for (int i  = 0; i < 4; i++)
	{
	  		printf("  Test1->%i\t", i);
			mergesort(test1[i], 5);
			if (verify(test1[i], 5) == 0)
				printf(RED "[KO]\n" RESET);
			else
				printf(GREEN "[OK]\n" RESET);
	}

	printf(CYAN "\nTest2: (random array of 100 elements)\n" RESET);
	mergesort(test2, 100);
	if (verify(test2, 100) == 0)
		printf(RED "[KO]\n" RESET);
	else
		printf(GREEN "[OK]\n" RESET);

	printf(CYAN "\nTest3: (random array of 1000 elements)\n" RESET);
	mergesort(test3, 1000);
	if (verify(test3, 1000) == 0)
		printf(RED "[KO]\n" RESET);
	else
		printf(GREEN "[OK]\n" RESET);

	printf(CYAN "\nTest4: (random array of %i elements)\n" RESET, len4);
	mergesort(test4, len4);
	if (verify(test4, len4) == 0)
		printf(RED "[KO]\n" RESET);
	else
		printf(GREEN "[OK]\n" RESET);
}
