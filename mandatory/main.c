/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:43:10 by rolee             #+#    #+#             */
/*   Updated: 2024/04/24 20:39:23 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_elements(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	size_t	sorted_cnt;

	current = stack->top->next;
	sorted_cnt = 0;
	while (current)
	{
		compare = stack->top;
		while (current != compare)
		{
			if (current->data == compare->data)
				return (IS_DUPLICATED);
			compare = compare->next;
		}
		if (current->prev->data < current->data)
			sorted_cnt += 1;
		current = current->next;
	}
	if (sorted_cnt == stack->size - 1)
		return (IS_SORTED);
	return (IS_VALID);
}

int main(int argc, char *argv[])
{
	t_stack_set		*stacks;
	int				elements_state;

	if (argc < 2)
		return (error_occurred("Error", 0));
	stacks = init_stack_set(argv + 1);
	if (stacks == NULL)
		return (error_occurred("Error", 0));
	elements_state = check_elements(stacks->a);
	if (elements_state == IS_SORTED)
		return (0);
	if (elements_state == IS_DUPLICATED)
		return (error_occurred("Error", 0));

	t_node *current = stacks->a->top;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}

	
	

	return 0;
}