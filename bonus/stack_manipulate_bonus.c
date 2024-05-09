/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:24 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 21:26:14 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	print_command("s", 1, stack->name);
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*moving_node;

	if (from->size == 0)
		return ;
	moving_node = from->top;
	from->top = from->top->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	moving_node->next = to->top;
	if (to->top)
		to->top->prev = moving_node;
	else
		to->bottom = moving_node;
	to->top = moving_node;
	from->size -= 1;
	to->size += 1;
	print_command("p", 1, to->name);
}

void	rotate(t_stack *stack)
{
	t_node	*moving_node;

	if (stack->size <= 1)
		return ;
	moving_node = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->bottom->next = moving_node;
	moving_node->prev = stack->bottom;
	moving_node->next = NULL;
	stack->bottom = moving_node;
	print_command("r", 1, stack->name);
}

void	reverse_rotate(t_stack *stack, int print)
{
	t_node	*moving_node;

	if (stack->size <= 1)
		return ;
	moving_node = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	moving_node->prev = NULL;
	moving_node->next = stack->top;
	stack->top->prev = moving_node;
	stack->top = moving_node;
	if (print == TRUE)
		print_command("rr", 2, stack->name);
}

void	reverse_rotate_all(t_stack *a, t_stack *b)
{
	reverse_rotate(a, FALSE);
	reverse_rotate(b, FALSE);
	print_command("rr", 2, 'r');
}
