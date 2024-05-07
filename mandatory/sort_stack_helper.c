/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:24:27 by rolee             #+#    #+#             */
/*   Updated: 2024/04/25 20:34:06 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int quick_sort_partition(int *arr, int start, int end);

void quick_sort(int *arr, int start, int end)
{
	if (start < end)
	{
		int pivot = quick_sort_partition(arr, start, end);
		quick_sort(arr, start, pivot-1);
		quick_sort(arr, pivot+1, end);
	}
}

static int quick_sort_partition(int *arr, int start, int end)
{
	int pivot;
	int left;
	int right;

	pivot = arr[start];
	left = start + 1;
	right = end;
	while(left <= right)
	{
		while(arr[left] <= pivot && left <= end)
			left++;
		while(arr[right] >= pivot && right > start)
			right--;
		if (left < right)
			swap_value(&arr[left], &arr[right]);
	}
	swap_value(&arr[start], &arr[right]);
	return right;
}

int	*first_partition(int size, int *pivot, t_stack_set *stacks)
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
			if (stacks->b->top->data <= pivot[SMALL])
			{
				rotate(stacks->b);
				op_cnt[RB]++;
			}
		}
	}
	return (op_cnt);
}