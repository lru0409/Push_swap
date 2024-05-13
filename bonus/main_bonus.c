/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:17:28 by rolee             #+#    #+#             */
/*   Updated: 2024/05/13 11:39:26 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	execute(t_stack_set	*stacks);
static int	is_duplicated(t_stack *stack);
static int	check_stack_sorted(t_stack_set	*stacks);
static int	end(char *msg, int fd, int ret, t_stack_set *stacks);

int	main(int argc, char *argv[])
{
	t_stack_set	*stacks;

	stacks = NULL;
	if (argc < 2)
		return (end("Error", STDERR_FILENO, EXIT_FAILURE, NULL));
	if (init_stack_set(argv + 1, &stacks) == EXIT_FAILURE)
		return (end(NULL, STDOUT_FILENO, EXIT_FAILURE, stacks));
	if (is_duplicated(stacks->a))
		return (end("Error", STDERR_FILENO, EXIT_FAILURE, stacks));
	if (execute(stacks) == EXIT_FAILURE)
		return (end("Error", STDERR_FILENO, EXIT_FAILURE, stacks));
	if (check_stack_sorted(stacks))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (end(NULL, STDOUT_FILENO, EXIT_SUCCESS, stacks));
}

static int	is_duplicated(t_stack	*stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top->next;
	while (current)
	{
		compare = stack->top;
		while (current != compare)
		{
			if (current->data == compare->data)
				return (TRUE);
			compare = compare->next;
		}
		current = current->next;
	}
	return (FALSE);
}

static int	execute(t_stack_set *stacks)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (execute_command(line, stacks) == EXIT_FAILURE)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

static int	check_stack_sorted(t_stack_set	*stacks)
{
	t_node	*current;

	if (stacks->a->size >= 2)
	{
		current = stacks->a->top->next;
		while (current)
		{
			if (current->prev->data > current->data)
				return (FALSE);
			current = current->next;
		}
	}
	if (stacks->b->size != 0)
		return (FALSE);
	return (TRUE);
}

static int	end(char *msg, int fd, int ret, t_stack_set *stacks)
{
	if (msg)
		ft_putendl_fd(msg, fd);
	clear_stack_set(stacks);
	return (ret);
}
