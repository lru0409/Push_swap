/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:40:34 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 20:33:53 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack *stack, int size, t_stack_set *stacks);
static int	*partition_a(int size, int *pivot, t_stack_set *stacks);
static int	*partition_b(int size, int *pivot, t_stack_set *stacks);

void	start_sort(t_stack_set *stacks)
{
	int	*pivot;
	int	*op_cnt;

	pivot = get_pivot(stacks->a->size, stacks->a);
	op_cnt = first_partition(stacks->a->size, pivot, stacks);
	sort_stack(stacks->a, op_cnt[RA], stacks);
	sort_stack(stacks->b, op_cnt[PB] - op_cnt[RB], stacks);
	sort_stack(stacks->b, op_cnt[RB], stacks);
}

static void	sort_stack(t_stack *stack, int size, t_stack_set *stacks)
{
	int	*pivot;
	int	*op_cnt;

	if (escape_handling(stack, size, stacks) == TRUE)
		return ;
	pivot = get_pivot(size, stack);
	if (stack->name == 'a')
	{
		op_cnt = partition_a(size, pivot, stacks);
		reverse_stacks(op_cnt[RA], op_cnt[RB], stacks);
		sort_stack(stacks->a, op_cnt[RA], stacks);
		sort_stack(stacks->b, op_cnt[RB], stacks);
		sort_stack(stacks->b, op_cnt[PB] - op_cnt[RB], stacks);
	}
	else
	{
		op_cnt = partition_b(size, pivot, stacks);
		sort_stack(stacks->a, op_cnt[PA] - op_cnt[RA], stacks);
		reverse_stacks(op_cnt[RA], op_cnt[RB], stacks);
		sort_stack(stacks->a, op_cnt[RA], stacks);
		sort_stack(stacks->b, op_cnt[RB], stacks);
	}
	free(pivot);
	free(op_cnt);
}

static int	*partition_a(int size, int *pivot, t_stack_set *stacks)
{
	int	*op_cnt;

	op_cnt = ft_calloc(3, sizeof(int));
	if (!op_cnt)
		exit(EXIT_FAILURE);
	while (size--)
	{
		if (pivot[BIG] < stacks->a->top->data)
		{
			rotate(stacks->a);
			op_cnt[RA]++;
		}
		else
		{
			push(stacks->a, stacks->b);
			op_cnt[PB]++;
			if (pivot[SMALL] < stacks->b->top->data)
			{
				rotate(stacks->b);
				op_cnt[RB]++;
			}
		}
	}
	return (op_cnt);
}

static int	*partition_b(int size, int *pivot, t_stack_set *stacks)
{
	int	*op_cnt;

	op_cnt = ft_calloc(3, sizeof(int));
	if (!op_cnt)
		exit(EXIT_FAILURE);
	while (size--)
	{
		if (stacks->b->top->data <= pivot[SMALL])
		{
			rotate(stacks->b);
			op_cnt[RB]++;
		}
		else
		{
			push(stacks->b, stacks->a);
			op_cnt[PA]++;
			if (stacks->a->top->data <= pivot[BIG])
			{
				rotate(stacks->a);
				op_cnt[RA]++;
			}
		}
	}
	return (op_cnt);
}
