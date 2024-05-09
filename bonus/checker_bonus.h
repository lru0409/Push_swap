/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:17:56 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 22:08:58 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS
# define CHECKER_BONUS

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

// stack_setup
int	init_stack_set(char *argv[], t_stack_set **stacks);
// stack_manipulate
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack, int print);
void	reverse_rotate_all(t_stack *a, t_stack *b);

// execute
int	execute(t_stack_set	*stacks);

// utils
void	free_strs(char **strs);
int	is_integer(char *str);
void	swap_value(int *first, int *second);

#endif