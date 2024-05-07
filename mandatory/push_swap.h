#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

#include <stdio.h>

# define FALSE 0
# define TRUE 1

# define IS_VALID 0
# define IS_SORTED 1
# define IS_DUPLICATED 2

# define RA 0
# define PB 1
# define RB 2
# define PA 1

# define SMALL 0
# define BIG 1

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	char	name;
	size_t	size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

typedef struct s_stack_set
{
	t_stack	*a;
	t_stack	*b;
}	t_stack_set;

// stack_setup.c
int	init_stack_set(char *argv[], t_stack_set **stacks);
// stack_clear.c
void	clear_stack_set(t_stack_set *stack_set);
// stack_manipulate.c
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_all(t_stack *a, t_stack *b);

void quick_sort(int *arr, int start, int end);
int	*first_partition(int size, int *pivot, t_stack_set *stacks);
void	start_sort(t_stack_set *stacks);

// utils.c
void	freeStrs(char **strs);
int		is_integer(char *str);
void	swap_value(int *first, int *second);

#endif