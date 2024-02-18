//42 header

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ctype.h"
# include "limits.h"
# include "libft/libft.h"
# include "stdlib.h"
# include "stdarg.h"
# include "ft_printf/ft_printf.h"

# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct t_solver t_solver;
typedef struct t_node t_node;
typedef struct t_stack t_stack;

//prepsat t_solve, arraye jsou zbytecne
typedef struct t_solver
{
	int		*matrix[3];
	int		matrix_len;
	int		bi_score;
} t_solver;

typedef struct t_node
{
	int		value;
	t_node	*next;
	t_node	*prev;
}	t_node;

typedef struct t_stack
{
	t_node	*head;
	size_t	len;
	char	name;
}	t_stack;

t_node	*create_node(int value, t_node *next, t_node *prev);
t_stack	*create_stack(t_node *head, size_t len, char name);
t_stack	*stack_init(int *arr, size_t len, char name);
void	free_stack(t_stack *stack);
void	print_stack(t_stack *stack);
void	node_insert(t_stack *to, t_node *node);
void	push(t_stack *from, t_stack *to);
void	rotate(int numstack, ...);
void	rev_rotate(int numstack, ...);
void	swap(int numstack, ...);
void	sort(int *input, size_t len);
void	mini_sort(t_stack	*stack);
int		get_stack_value(t_stack *stack, int index);
int		rotation_sequence(t_stack *to, int movedist, int head);
int		rotation_sequence_two(t_stack *to, t_stack *from, t_solver *solver, int head);
int		rotation_distance(int stacklen, int head, int index, int len);
int		get_index(int from_head, t_stack *to, int head);
t_solver	*create_solver(t_stack *from, t_stack *to, int head_from, int head_to);
void	free_solver(t_solver *solver);



#endif
