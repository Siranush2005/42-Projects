/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_up_to_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:08:44 by sarakely          #+#    #+#             */
/*   Updated: 2026/10/06 16:49:41 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_2_items(t_stack *a, t_ops *ops)
{
	if (a->top->index > a->top->next->index)
		sa(a, ops);
}

void	sorting_3_items(t_stack *a, t_ops *ops)
{
	int	first;
	int	second;
	int	third;
	int	max;

	first = a->top->index;
	second = a->top->next->index;
	third = a->top->next->next->index;
	max = first;
	if (second > max)
		max = second;
	if (third > max)
		max = third;
	if (first == max)
		ra(a, ops);
	else if (second == max)
		rra(a, ops);
	if (a->top->index > a->top->next->index)
		sa(a, ops);
}

static void	push_min(t_stack *a, t_stack *b, int min_pos, t_ops *ops)
{
	int	i;

	if (min_pos <= a->size / 2)
		while (min_pos--)
			ra(a, ops);
	else
	{
		i = a->size - min_pos;
		while (i--)
			rra(a, ops);
	}
	pb(a, b, ops);
}

// We also consider the case where a->size == 4.
void	sorting_5_items(t_stack *a, t_stack *b, t_ops *ops)
{
	if (a->size == 4)
		push_min(a, b, get_min_pos(a), ops);
	else if (a->size == 5)
	{
		push_min(a, b, get_min_pos(a), ops);
		push_min(a, b, get_min_pos(a), ops);
	}
	sorting_3_items(a, ops);
	pa(a, b, ops);
	pa(a, b, ops);
}
