/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 21:43:03 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 22:12:41 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int execute_command(char *command, t_stack_set *stacks);

int	execute(t_stack_set	*stacks)
{
	char	*line;

	while (TRUE)
	{
		line = get_next_line(STDOUT_FILENO);
		if (!line)
			break;
		if (execute_command(line, stacks) == EXIT_FAILURE) // TODO : 검토하자
		{
			free(line);
			ft_putendl_fd("Error", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

static int execute_command(char *command, t_stack_set *stacks)
{
	// TODO : 작성 중...
	return (EXIT_SUCCESS);
}
