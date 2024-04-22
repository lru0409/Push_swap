#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

#endif