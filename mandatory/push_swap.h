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

// 여기 좀 합치고, PBR, PAR 이런 것도 없애면 좋을 듯
// A 스택 작업
# define RA 0
# define PB 1
# define PBR 2

// B 스택 작업
# define RB 0
# define PA 1
# define PAR 2

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

void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_all(t_stack *a, t_stack *b);

#endif