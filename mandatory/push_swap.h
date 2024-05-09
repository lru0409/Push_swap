/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:36:57 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 20:48:55 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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

// stack_setup
int		init_stack_set(char *argv[], t_stack_set **stacks);
// stack_clear
void	clear_stack_set(t_stack_set *stack_set);
// stack_manipulate
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack, int print);
void	reverse_rotate_all(t_stack *a, t_stack *b);

// small_scale_sort
void	small_scale_sort(t_stack_set *stacks);

// sort_stack
void	start_sort(t_stack_set *stacks);
int		*first_partition(int size, int *pivot, t_stack_set *stacks);
int		escape_handling(t_stack *stack, int size, t_stack_set *stacks);
void	reverse_stacks(int ra_cnt, int rb_cnt, t_stack_set *stacks);
int		*get_pivot(int size, t_stack *stack);
int		*get_sorted_arr(int size, t_stack *stack);

// utils.c
void	free_strs(char **strs);
int		is_integer(char *str);
void	swap_value(int *first, int *second);
void	print_command(char *cmd, size_t cmd_size, char stack);

#endif