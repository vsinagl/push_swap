//42 header
#ifndef		PUSHSWAP_H
 #define	PUSHSWAP_H
 
 //#include "libft.h"
 #include "ctype.h"
 #include "stdio.h"
 #include "stdlib.h"

typedef struct stack{
		size_t	len;
		size_t	head;
		int		*self;
		char	name;
} stack;

void	print_stack(stack *p_stack);
void	swap(stack *p_stack);
void	swap_both(stack *p_stackA, stack *p_stackB);


#endif
