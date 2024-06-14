#ifndef MERGESORT_T_H
# define MERGESORT_T_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../pushswap.h"

//colordefines
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define WHITE   "\x1b[37m"
#define RESET   "\x1b[0m"

//function defines:
int	*int_copy(int *arr, int len);
int	*mergesort(int *arr, int len);
void	merge(int *arr, int *arr1, int *arr2, int len1, int len2);
int	*int_copy_fromstack(t_stack *stack, int i, int len);

#endif
