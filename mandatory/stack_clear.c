/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:45:48 by rolee             #+#    #+#             */
/*   Updated: 2024/05/07 20:46:25 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_all_nodes(t_stack *stack);

void	clear_stack_set(t_stack_set *stacks)
{
	if (!stacks)
		return;
	if (stacks->a) {
		clear_all_nodes(stacks->a);
		free(stacks->a);
	}
	if (stacks->b) {
		clear_all_nodes(stacks->b);
		free(stacks->b);
	}
	free(stacks);
}

static void	clear_all_nodes(t_stack *stack)
{
	t_node *current;
	t_node *next;

	if (stack == NULL)
		return;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
