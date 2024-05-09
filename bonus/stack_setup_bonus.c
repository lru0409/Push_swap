/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setup_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:06:51 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 22:05:39 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(char name);
static int		set_a_stack(t_stack *a_stack, char *argv[]);
static int		push_back(t_stack *stack, int data);

int	init_stack_set(char *argv[], t_stack_set **stacks)
{
	*stacks = (t_stack_set *)malloc(sizeof(t_stack_set));
	if (!stacks)
		return (EXIT_FAILURE);
	(*stacks)->a = NULL;
	(*stacks)->b = NULL;
	(*stacks)->a = init_stack('a');
	if (!(*stacks)->a)
		return (EXIT_FAILURE);
	if (set_a_stack((*stacks)->a, argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	(*stacks)->b = init_stack('b');
	if (!(*stacks)->b)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static t_stack	*init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

static int	set_a_stack(t_stack *a_stack, char *argv[])
{
	char	**strs;
	int		str_idx;

	while (*argv)
	{
		strs = ft_split(*argv, ' ');
		if (!strs)
			return (EXIT_FAILURE);
		str_idx = 0;
		while (strs[str_idx])
		{
			if (is_integer(strs[str_idx]) == FALSE || \
				push_back(a_stack, ft_atoi(strs[str_idx])) == EXIT_FAILURE)
			{
				ft_putendl_fd("Error", STDERR_FILENO);
				free_strs(strs);
				return (EXIT_FAILURE);
			}
			str_idx++;
		}
		free_strs(strs);
		argv++;
	}
	return (EXIT_SUCCESS);
}

static int	push_back(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (EXIT_FAILURE);
	new_node->data = data;
	new_node->prev = stack->bottom;
	new_node->next = NULL;
	if (stack->bottom)
		stack->bottom->next = new_node;
	else
		stack->top = new_node;
	stack->bottom = new_node;
	stack->size += 1;
	return (EXIT_SUCCESS);
}
