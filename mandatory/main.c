/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:43:10 by rolee             #+#    #+#             */
/*   Updated: 2024/05/07 20:56:55 by rolee            ###   ########.fr       */
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
			sorted_cnt++;
		current = current->next;
	}
	if (sorted_cnt == stack->size - 1)
		return (IS_SORTED);
	return (IS_VALID);
}

int	end(char *msg, int ret, t_stack_set *stacks)
{
	if (msg)
		ft_putendl_fd(msg, STDOUT_FILENO);
	clear_stack_set(stacks);
	return (ret);
}

int main(int argc, char *argv[])
{
	t_stack_set		*stacks;
	int				elements_state;

	stacks = NULL;
	if (argc < 2)
		return (end("Error", 0, NULL));
	if (init_stack_set(argv + 1, &stacks) == EXIT_FAILURE)
		return (end(NULL, 0, stacks));
	elements_state = check_elements(stacks->a);
	if (elements_state == IS_SORTED)
		return (end(NULL, 0, stacks));
	if (elements_state == IS_DUPLICATED)
		return (end("Error", 0, stacks));
	
	// start_sort(stacks);

	t_node *current = stacks->a->top;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}

	return 0;
}