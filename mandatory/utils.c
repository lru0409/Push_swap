/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:42:50 by rolee             #+#    #+#             */
/*   Updated: 2024/04/24 20:34:29 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int error_occurred(char *msg, int ret)
{
	ft_putendl_fd(msg, STDOUT_FILENO);
	return (ret);
}

void freeStrs(char **strs)
{
	int idx;

	idx = 0;
	while (strs[idx])
	{
		free(strs[idx]);
		idx++;
	}
	free(strs);
}

int is_integer(char *str)
{
	int idx;

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
