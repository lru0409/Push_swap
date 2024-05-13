/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:43:03 by rolee             #+#    #+#             */
/*   Updated: 2024/05/13 11:39:33 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	execute_swap(char *command, t_stack_set *stacks);
static void	execute_push(char *command, t_stack_set *stacks);
static void	execute_rotate(char *command, t_stack_set *stacks);
static void	execute_reverse_rotate(char *command, t_stack_set *stacks);

int	execute_command(char *command, t_stack_set *stacks)
{
	if (command[0] == 's' && command[2] == '\n' && \
			(command[1] == 'a' || command[1] == 'b' || command[1] == 's'))
		execute_swap(command, stacks);
	else if (command[0] == 'p' && command[2] == '\n' && \
			(command[1] == 'a' || command[1] == 'b'))
		execute_push(command, stacks);
	else if (command[0] == 'r' && command[2] == '\n' && \
			(command[1] == 'a' || command[1] == 'b' || command[1] == 'r'))
		execute_rotate(command, stacks);
	else if (ft_strncmp(command, "rr", 2) == 0 && command[3] == '\n' && \
			(command[2] == 'a' || command[2] == 'b' || command[2] == 'r'))
		execute_reverse_rotate(command, stacks);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	execute_swap(char *command, t_stack_set *stacks)
{
	if (command[1] == 'a')
		swap(stacks->a);
	else if (command[1] == 'b')
		swap(stacks->b);
	else if (command[1] == 's')
	{
		swap(stacks->a);
		swap(stacks->b);
	}
}

static void	execute_push(char *command, t_stack_set *stacks)
{
	if (command[1] == 'a')
		push(stacks->b, stacks->a);
	else if (command[1] == 'b')
		push(stacks->a, stacks->b);
}

static void	execute_rotate(char *command, t_stack_set *stacks)
{
	if (command[1] == 'a')
		rotate(stacks->a);
	else if (command[1] == 'b')
		rotate(stacks->b);
	else if (command[1] == 'r')
	{
		rotate(stacks->a);
		rotate(stacks->b);
	}
}

static void	execute_reverse_rotate(char *command, t_stack_set *stacks)
{
	if (command[2] == 'a')
		reverse_rotate(stacks->a);
	else if (command[2] == 'b')
		reverse_rotate(stacks->b);
	else if (command[2] == 'r')
		reverse_rotate_all(stacks->a, stacks->b);
}
