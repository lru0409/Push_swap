/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:40:34 by rolee             #+#    #+#             */
/*   Updated: 2024/04/24 21:21:09 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	start_sort()
{
	
}

void reverse_stacks(int ra_cnt, int rb_cnt, t_stack_set *stacks)
{
	int count;

	count = 0;
	while (count < ra_cnt || count < rb_cnt)
	{
		if (count < ra_cnt && count < rb_cnt)
			reverse_stacks(ra_cnt, rb_cnt, stacks);
		else if (count < ra_cnt)
			reverse_rotate(stacks->a);
		else
			reverse_rotate(stacks->b);
		count++;
	}
}

int	*partition_a(int size, int small, int big, t_stack_set *stacks)
{
	int op_cnt[3];

	ft_memset(op_cnt, 0, 3);
	while (size--)
	{
		if (big < stacks->a->top->data)
		{
			rotate(stacks->a);
			op_cnt[RA]++;
		}
		else
		{
			push(stacks->a, stacks->b);
			op_cnt[PB]++;
			if (small < stacks->b->top->data)
			{
				rotate(stacks->b);
				op_cnt[PBR]++;
			}
		}
	}
	return (op_cnt);
}

int	*partition_b(int size, int small, int big, t_stack_set *stacks)
{
	int *op_cnt;

	op_cnt = (int *)ft_calloc(3, sizeof(int));
	while (size--)
	{
		if (stacks->b->top->data <= small)
		{
			rotate(stacks->b);
			op_cnt[RB]++;
		}
		else
		{
			push(stacks->b, stacks->a);
			op_cnt[PA]++;
			if (stacks->a->top->data <= big)
			{
				rotate(stacks->a);
				op_cnt[PAR]++;
			}
		}
	}
	return (op_cnt);
}

void	sort_stack()
{
	
}