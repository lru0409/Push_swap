/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:43:10 by rolee             #+#    #+#             */
/*   Updated: 2024/04/23 21:59:08 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	argc = 0;
	t_stack_set *stacks = init_stack_set(argv + 1);

	t_node *current = stacks->a->top;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}

	return 0;
}