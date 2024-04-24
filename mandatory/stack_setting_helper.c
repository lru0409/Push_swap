/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setting_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:56:32 by rolee             #+#    #+#             */
/*   Updated: 2024/04/24 20:15:50 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_node	*create_node(int data)
// {
// 	t_node *new_node = (t_node *)malloc(sizeof(t_node));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->data = data;
// 	new_node->prev = NULL;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// void	push_front(t_stack *stack, t_node *new_node)
// {
// 	new_node->prev = NULL;
// 	new_node->next = stack->top;
// 	if (stack->top)
// 		stack->top->prev = new_node;
// 	else
// 		stack->bottom = new_node;
// 	stack->top = new_node;
// 	stack->size += 1;
// }

// void	push_back(t_stack *stack, t_node *new_node)
// {
// 	new_node->prev = stack->bottom;
// 	new_node->next = NULL;
// 	if (stack->bottom)
// 		stack->bottom->next = new_node;
// 	else
// 		stack->top = new_node;
// 	stack->bottom = new_node;
// 	stack->size += 1;
// }

int	push_back(t_stack *stack, int data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
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

void	clear_all_nodes(t_stack *stack)
{
	t_node *current;
	t_node *next;

	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
