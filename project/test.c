#include "../pushswap.h"
#include "stdio.h"

//head: 1,3,3,3,8,7,2
int	rotation_distance_test(int stacklen, int head, int index, int len)
{
	int		rr_distance;
	int		r_distance;


	if (index == len && stacklen == len)
		index = 0;
	if (index == head)
		return (0);
	if (head > index)
	{
		rr_distance = head - index;
		r_distance = stacklen - (head - index);
	}
	else
	{
		rr_distance = stacklen - (index - head);
		r_distance = index - head;
	}
	printf("rr_distance = %i\n",rr_distance);
	printf("r_distance = %i\n",r_distance);
	if (r_distance <= rr_distance)
		return (r_distance);
	else
		return (-1 * rr_distance);
}

int main()
{
	//int	array[5] = {2, 5, 6, 7, 3};
	int		head = 2;
	int		index = 3;
	int		stacklen = 5;
	int		len = 3;
	//declaration of values
	int		rr_distance = 0;
	int		r_distance = 0;

	int test = rotation_distance_test(stacklen, head, index, len);
	printf("return value: %i\n", test);
	return(0);
}
		
