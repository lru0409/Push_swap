/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:24 by rolee             #+#    #+#             */
/*   Updated: 2024/04/24 21:04:58 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_command(char *cmd, size_t cmd_size, char stack);

void	swap(t_stack *stack)
{
	if (stack->size < 2)
		return;
	int temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	printCommand("s", 1, stack->name);
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*moving_node;

	if (from->size == 0)
		return;
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
	printCommand("p", 1, to->name);
}

void	rotate(t_stack *stack)
{
	t_node *moving_node;

	if (stack->size <= 1)
		return;
	moving_node = stack->top;
	stack->top = stack->top->next;
	stack->top->prev = NULL;
	stack->bottom->next = moving_node;
	moving_node->prev = stack->bottom;
	stack->bottom = moving_node;
	printCommand("r", 1, stack->name);
}

void	reverse_rotate(t_stack *stack)
{
	t_node *moving_node;

	if (stack->size <= 1)
		return;
	moving_node = stack->bottom;
	stack->bottom = stack->bottom->prev;
	stack->bottom->next = NULL;
	moving_node->prev = NULL;
	moving_node->next = stack->top;
	stack->top->prev = moving_node;
	stack->top = moving_node;
	printCommand("rr", 2, stack->name);
}

void	reverse_rotate_all(t_stack *a, t_stack *b)
{
	reverseRotate(a);
	reverseRotate(b);
	printCommand("rr", 2, 'r');
}

static void print_command(char *cmd, size_t cmd_size, char stack)
{
	write(STDOUT_FILENO, cmd, cmd_size);
	write(STDOUT_FILENO, &stack, 1);
	write(STDOUT_FILENO, "\n", 1);
}