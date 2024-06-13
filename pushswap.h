//42 header

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "ctype.h"
# include "limits.h"
# include "libft2/libft.h"
# include "stdlib.h"
# include "stdarg.h"
# include "ft_printf/ft_printf.h"

# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct s_solver t_solver;
typedef struct s_node t_node;
typedef struct s_stack t_stack;
typedef struct s_chunk t_chunk;
typedef struct s_mergestruct t_mergestruct;


enum			e_loc
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B
};

typedef struct s_result
{
	int q1;
	int q2;
	int q3;
	int q4;
} t_result;

typedef struct s_solver
{
	int		*matrix[3];
	int		matrix_len;
	int		bi_score;
} t_solver;

typedef struct s_node
{
	int		value;
	t_node	*next;
	t_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		head_i;
	size_t	len;
	char	name;
}	t_stack;

typedef struct s_chunk
{
	enum e_loc loc;
	int	len;
}	t_chunk;

typedef struct s_mergestruct
{
	int	border1;
	int	border2;
	t_stack *from;
	t_stack *to;
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_mergestruct;

//typedef struct t_mergestruct defined here:	

t_node		*create_node(int value, t_node *next, t_node *prev);
t_stack		*create_stack(t_node *head, size_t len, char name);
t_stack		*stack_init(int *arr, size_t len, char name);
void		free_stack(t_stack *stack);
void		print_stack(t_stack *stack);
void		node_insert(t_stack *to, t_node *node);
void		push(t_stack *from, t_stack *to);
void		rotate(int numstack, ...);
void		rev_rotate(int numstack, ...);
void		swap(int numstack, ...);
void		sort(int *input, size_t len);
void		mini_sort(t_stack	*stack);
int			get_stack_value(t_stack *stack, int index);
void		rotation_sequence(t_stack *to, int movedist);
void		rotation_sequence_two(t_stack *to, t_stack *from, t_solver *solver);
int			rotation_distance(int stacklen, int head, int index, int len);
void		injection_sort(t_stack *from, t_stack *to);
void		injection_sort2(t_stack *from, t_stack *to, int len, int min);
void		sort_just_selective(int *input, size_t len);
int			get_index(int from_head, t_stack *to, int head);
int			*mergesort(int* arr, int len);
int			*int_copy_fromStack(t_stack *stack, int i, int len);
t_solver	*create_solver(t_stack *from, t_stack *to, int head_from, int head_to);
void		free_solver(t_solver *solver);
int			*mergesort(int* arr, int len);
int			*int_copy(int *arr, int len);
void		push_all(t_stack *from, t_stack *to);
void	middleway(t_stack *stackA, t_stack *stackB);
void		merge_sort(int *input, size_t len);
void		swap_sort(t_stack	*stack);
void		six_sort(t_stack *stackA, t_stack *stackB);

#endif
