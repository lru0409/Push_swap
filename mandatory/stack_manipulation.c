/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:24 by rolee             #+#    #+#             */
/*   Updated: 2024/04/22 21:45:12 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void printCommand(char *cmd, size_t cmd_size, char stack);

void	swap(t_stack *stack)
{
	if (stack->size < 2)
		return;
	int temp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = temp;
	printCommand("s", 1, stack->name);
}

void	push(t_stack *pop_stack, t_stack *push_stack)
{
	t_node	*moving_node;

	if (pop_stack->size == 0)
		return;
	moving_node = pop_stack->top;
	pop_stack->top = pop_stack->top->next;
	if (pop_stack->top)
		pop_stack->top->prev = NULL;
	else
		pop_stack->bottom = NULL;
	moving_node->next = push_stack->top;
	if (push_stack->top)
		push_stack->top->prev = moving_node;
	else
		push_stack->bottom = moving_node;
	push_stack->top = moving_node;
	pop_stack->size -= 1;
	push_stack->size += 1;
	printCommand("p", 1, push_stack->name);
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

void	reverseRotate(t_stack *stack)
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

void	reverseRotateAll(t_stack *a, t_stack *b)
{
	reverseRotate(a);
	reverseRotate(b);
	printCommand("rr", 2, 'r');
}

static void printCommand(char *cmd, size_t cmd_size, char stack)
{
	write(STDOUT_FILENO, cmd, cmd_size);
	write(STDOUT_FILENO, &stack, 1);
	write(STDOUT_FILENO, "\n", 1);
}