/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:24:27 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 20:45:08 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_elements(t_stack *stack, int size, t_stack_set *stacks);
static int	is_sorted(t_stack *stack, int size);

int	*first_partition(int size, int *pivot, t_stack_set *stacks)
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
			if (stacks->b->top->data <= pivot[SMALL])
			{
				rotate(stacks->b);
				op_cnt[RB]++;
			}
		}
	}
	return (op_cnt);
}

int	escape_handling(t_stack *stack, int size, t_stack_set *stacks)
{
	if (size < 3)
	{
		sort_elements(stack, size, stacks);
		return (TRUE);
	}
	if (is_sorted(stack, size) == TRUE)
	{
		if (stack->name == 'b')
		{
			while (size--)
				push(stacks->b, stacks->a);
		}
		return (TRUE);
	}
	return (FALSE);
}

static void	sort_elements(t_stack *stack, int size, t_stack_set *stacks)
{
	if (stack->name == 'b' && size == 1)
	{
		push(stacks->b, stacks->a);
	}
	else if (stack->name == 'b' && size == 2)
	{
		push(stacks->b, stacks->a);
		push(stacks->b, stacks->a);
		stack = stacks->a;
	}
	if (stack->name == 'a' && size == 2)
	{
		if (stack->top->next->data < stack->top->data)
			swap(stack);
	}
}

static int	is_sorted(t_stack *stack, int size)
{
	int		count;
	t_node	*current;

	if (stack->size < 2)
		return (TRUE);
	count = 0;
	current = stack->top->next;
	while (current && count++ < size - 1)
	{
		if (stack->name == 'a' && current->data < current->prev->data)
			return (FALSE);
		else if (stack->name == 'b' && current->prev->data < current->data)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

void	reverse_stacks(int ra_cnt, int rb_cnt, t_stack_set *stacks)
{
	int	count;

	count = 0;
	while (count < ra_cnt || count < rb_cnt)
	{
		if (count < ra_cnt && count < rb_cnt)
			reverse_rotate_all(stacks->a, stacks->b);
		else if (count < ra_cnt)
			reverse_rotate(stacks->a, TRUE);
		else
			reverse_rotate(stacks->b, TRUE);
		count++;
	}
}
