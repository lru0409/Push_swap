/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_helper2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:15:08 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 20:49:06 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	quick_sort(int *arr, int start, int end);
static int	quick_sort_partition(int *arr, int start, int end);

int	*get_pivot(int size, t_stack *stack)
{
	int	*sorted_arr;
	int	*pivot;

	sorted_arr = get_sorted_arr(size, stack);
	pivot = (int *)malloc(sizeof(int) * 2);
	if (!pivot)
		exit(EXIT_FAILURE);
	pivot[SMALL] = sorted_arr[(size * 1 / 3) - 1];
	pivot[BIG] = sorted_arr[(size * 2 / 3) - 1];
	free(sorted_arr);
	return (pivot);
}

int	*get_sorted_arr(int size, t_stack *stack)
{
	int		*arr;
	t_node	*current;
	int		idx;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(EXIT_FAILURE);
	current = stack->top;
	idx = 0;
	while (idx < size)
	{
		arr[idx++] = current->data;
		current = current->next;
		if (!current)
			break ;
	}
	quick_sort(arr, 0, size - 1);
	return (arr);
}

static void	quick_sort(int *arr, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = quick_sort_partition(arr, start, end);
		quick_sort(arr, start, pivot - 1);
		quick_sort(arr, pivot + 1, end);
	}
}

static int	quick_sort_partition(int *arr, int start, int end)
{
	int	pivot;
	int	left;
	int	right;

	pivot = arr[start];
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (arr[left] <= pivot && left <= end)
			left++;
		while (arr[right] >= pivot && right > start)
			right--;
		if (left < right)
			swap_value(&arr[left], &arr[right]);
	}
	swap_value(&arr[start], &arr[right]);
	return (right);
}
