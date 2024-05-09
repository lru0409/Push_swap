/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:42:50 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 20:46:39 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strs(char **strs)
{
	int	idx;

	idx = 0;
	while (strs[idx])
	{
		free(strs[idx]);
		idx++;
	}
	free(strs);
}

int	is_integer(char *str)
{
	int	idx;

	idx = 0;
	if (str[idx] == '-')
		idx++;
	while (str[idx])
	{
		if (str[idx] < '0' || '9' < str[idx])
			return (FALSE);
		idx++;
	}
	if (ft_atoi(str) < -2147483648 || 2147483647 < ft_atoi(str))
		return (FALSE);
	if (11 < idx)
		return (FALSE);
	return (TRUE);
}

void	swap_value(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

void	print_command(char *cmd, size_t cmd_size, char stack)
{
	write(STDOUT_FILENO, cmd, cmd_size);
	write(STDOUT_FILENO, &stack, 1);
	write(STDOUT_FILENO, "\n", 1);
}
