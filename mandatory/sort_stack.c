/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:40:34 by rolee             #+#    #+#             */
/*   Updated: 2024/05/07 22:06:01 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

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

int	*partition_a(int size, int *pivot, t_stack_set *stacks)
{
	int *op_cnt;

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

int	*partition_b(int size, int *pivot, t_stack_set *stacks)
{
	int *op_cnt;

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

int	*get_stack_arr(int size, t_stack *stack)
{
	int		*arr;
	int		idx;
	t_node	*current;
	
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(EXIT_FAILURE);
	idx = 0;
	current = stack->top;
	while (size--)
	{
		arr[idx++] = current->data;
		current = current->next;
	}
	return arr;
}

int	*get_sorted_arr(int size, t_stack *stack)
{
	int		*arr;
	t_node	*current;
	
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(EXIT_FAILURE);
	current = stack->top;
	for(int idx = 0; idx < size; idx++)
	{
		arr[idx] = current->data;
		current = current->next;
		if (!current)
			break;
	}
	quick_sort(arr, 0, size - 1);
	return arr;
}

int	*get_pivot(int size, t_stack *stack)
{
	int		*sorted_arr;
	int		*pivot;

	sorted_arr = get_sorted_arr(size, stack);
	pivot = (int *)malloc(sizeof(int) * 2);
	if (!pivot)
		exit(EXIT_FAILURE);
	pivot[SMALL] = sorted_arr[(size * 1/3) - 1];
	pivot[BIG] = sorted_arr[(size * 2/3) - 1];
	free(sorted_arr);
	return (pivot);
}

int	is_sorted(t_stack *stack, int size)
{
	int		count;
	t_node	*current;

	count = 0;
	current = stack->top->next;
	while (count < size - 1)
	{
		if (stack->name == 'a' && current->data < current->prev->data)
			return (FALSE);
		else if (stack->name == 'b' && current->prev->data < current->data)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

void	sort_elements(t_stack *stack, int size, t_stack_set *stacks)
{
	if (stack->name == 'b' && size == 1) {
		push(stacks->b, stacks->a);
	} else if (stack->name == 'b' && size == 2) {
		push(stacks->b, stacks->a);
		push(stacks->b, stacks->a);
		stack = stacks->a;
	}
	if (stack->name == 'a' && size == 2) {
		if (stack->top->next->data < stack->top->data)
			swap(stack);
	}
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

void	sort_stack(t_stack *stack, int size, t_stack_set *stacks)
{
	int *pivot;
	int *op_cnt;

	if (escape_handling(stack, size, stacks) == TRUE)
		return;
	pivot = get_pivot(size, stack);
	if (stack->name == 'a') {
		op_cnt = partition_a(size, pivot, stacks);
		reverse_stacks(op_cnt[RA], op_cnt[RB], stacks);
		sort_stack(stacks->a, op_cnt[RA], stacks);
		sort_stack(stacks->b, op_cnt[RB], stacks);
		sort_stack(stacks->b, op_cnt[PB] - op_cnt[RB], stacks);
	} else {
		op_cnt = partition_b(size, pivot, stacks);
		sort_stack(stacks->a, op_cnt[PA] - op_cnt[RA], stacks);
		reverse_stacks(op_cnt[RA], op_cnt[RB], stacks);
		sort_stack(stacks->a, op_cnt[RA], stacks);
		sort_stack(stacks->b, op_cnt[RB], stacks);
	}
	free(pivot);
	free(op_cnt);
}

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
