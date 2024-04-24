/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:06:51 by rolee             #+#    #+#             */
/*   Updated: 2024/04/24 20:39:03 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *	init_stack(char name);
static int			set_a_stack(t_stack *a_stack, char *argv[]);
static void			clear_stack_set(t_stack_set *stack_set);

t_stack_set *	init_stack_set(char *argv[])
{
	t_stack_set *stack_set = (t_stack_set *)malloc(sizeof(t_stack_set));
	if (!stack_set)
		return NULL;
	stack_set->a = NULL;
	stack_set->b = NULL;
	stack_set->a = init_stack('a');
	if (!stack_set->a)
	{
		clear_stack_set(stack_set);
		return (NULL);
	}
	if (set_a_stack(stack_set->a, argv) == EXIT_FAILURE)
	{
		clear_stack_set(stack_set);
		return (NULL);
	}
	stack_set->b = init_stack('b');
	if (!stack_set->b)
	{
		clear_stack_set(stack_set);
		return (NULL);
	}
	return stack_set;
}

static t_stack *	init_stack(char name)
{
	t_stack	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return NULL;
	stack->name = name;
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return stack;
}

static int	set_a_stack(t_stack *a_stack, char *argv[])
{
	char **strs;
	int str_idx;

	while (*argv)
	{
		strs = ft_split(*argv, ' ');
		if (!strs)
			return (EXIT_FAILURE);
		str_idx = 0;
		while (strs[str_idx])
		{
			if (is_integer(strs[str_idx]) == FALSE ||
				push_back(a_stack, ft_atoi(strs[str_idx])) == EXIT_FAILURE)
			{
				freeStrs(strs);
				return (EXIT_FAILURE);
			}
			str_idx++;
		}
		freeStrs(strs);
		argv++;
	}
	return (EXIT_SUCCESS);
}

static void	clear_stack_set(t_stack_set *stack_set)
{
	clear_all_nodes(stack_set->a);
	free(stack_set->a);
	clear_all_nodes(stack_set->b);
	free(stack_set->a);
	free(stack_set);
}
