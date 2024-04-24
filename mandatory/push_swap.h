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

t_stack_set *init_stack_set(char *argv[]);

int		error_occurred(char *msg, int ret);
void	freeStrs(char **strs);
int		is_integer(char *str);

int		push_back(t_stack *stack, int data);
void	clear_all_nodes(t_stack *stack);


#endif