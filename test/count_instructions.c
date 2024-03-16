#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int	main(void)
{
	char *line = NULL;
	size_t len = 0;
	FILE *pipe = NULL;
	int count = 0;
	

	pipe = popen("bash ~/Code/42/push_swap/test/injection2_test.sh", "r");
	while(getline(&line, &len, pipe) != -1)
		count++;
	printf("final sorted array: %s\n", line);
	printf("number of instructions: %i\n", count);
	return(0);
}


	
