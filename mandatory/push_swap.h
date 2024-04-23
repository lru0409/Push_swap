#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

#include <stdio.h>

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

void	freeStrs(char **strs);

t_node	*create_node(int data);
void	push_back(t_stack *stack, t_node *new_node);
void	clear_all_nodes(t_stack *stack);


#endif