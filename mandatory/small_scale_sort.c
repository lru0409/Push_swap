/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_scale_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:12:41 by rolee             #+#    #+#             */
/*   Updated: 2024/05/09 20:36:42 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two_elems(t_stack *a);
static void	sort_three_elems(t_stack *a);
static void	sort_four_elems(t_stack *a, t_stack *b);
static void	sort_five_elems(t_stack *a, t_stack *b);

void	small_scale_sort(t_stack_set *stacks)
{
	if (stacks->a->size == 2)
		sort_two_elems(stacks->a);
	else if (stacks->a->size == 3)
		sort_three_elems(stacks->a);
	else if (stacks->a->size == 4)
		sort_four_elems(stacks->a, stacks->b);
	else if (stacks->a->size == 5)
		sort_five_elems(stacks->a, stacks->b);
}

static void	sort_two_elems(t_stack *a)
{
	if (a->size < 2)
		return ;
	if (a->top->next->data < a->top->data)
		swap(a);
}

static void	sort_three_elems(t_stack *a)
{
	int	*first;
	int	*second;
	int	*third;

	if (a->size < 3)
		return ;
	first = &(a->top->data);
	second = &(a->top->next->data);
	third = &(a->top->next->next->data);
	if ((*first < *second && *second > *third && *first < *third) || \
		(*first > *second && *second > *third && *first > *third))
		swap(a);
	if (*first > *second && *second < *third && *first < *third)
		swap(a);
	else if (*first < *second && *second > *third && *first > *third)
		reverse_rotate(a, TRUE);
	else if (*first > *second && *second < *third && *first > *third)
		rotate(a);
}

static void	sort_four_elems(t_stack *a, t_stack *b)
{
	int		*sorted_arr;
	int		pivot;
	int		count;

	if (a->size < 4)
		return ;
	sorted_arr = get_sorted_arr(a->size, a);
	pivot = sorted_arr[1];
	free(sorted_arr);
	count = 0;
	while (count++ < 4)
	{
		if (a->top->data > pivot)
			rotate(a);
		else
			push(a, b);
	}
	sort_two_elems(a);
	if (b->top->data < b->top->next->data)
		swap(b);
	push(b, a);
	push(b, a);
}

static void	sort_five_elems(t_stack *a, t_stack *b)
{
	int		*sorted_arr;
	int		pivot;
	int		count;

	sorted_arr = get_sorted_arr(a->size, a);
	pivot = sorted_arr[1];
	free(sorted_arr);
	count = 0;
	while (count++ < 5)
	{
		if (a->top->data > pivot)
			rotate(a);
		else
			push(a, b);
	}
	sort_three_elems(a);
	if (b->top->data < b->top->next->data)
		swap(b);
	push(b, a);
	push(b, a);
}
