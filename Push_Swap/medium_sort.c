/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:09:06 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:08:01 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_max(t_stack *b, t_ops *ops, int max_pos)
{
	if (max_pos <= b->size / 2)
		while (max_pos--)
			rb(b, ops);
	else
		while (++max_pos <= b->size)
			rrb(b, ops);
}

static void	fill_back_to_a(t_stack *a, t_stack *b, t_ops *ops)
{
	int	max_pos;

	while (!is_empty(b))
	{
		max_pos = get_max_pos(b);
		rotate_to_max(b, ops, max_pos);
		pa(a, b, ops);
	}
}

static int	find_chunk_size(int n)
{
	int	i;

	i = 1;
	while (i * i < n)
		i++;
	return (i);
}

void	medium_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	chunk_size;
	int	curr_max;
	int	count;

	chunk_size = find_chunk_size(a->size);
	curr_max = chunk_size - 1;
	count = 0;
	while (!is_empty(a))
	{
		if (a->top->index <= curr_max)
		{
			pb(a, b, ops);
			count++;
			if (b->top->index <= curr_max - (chunk_size / 2))
				rb(b, ops);
		}
		else
			ra(a, ops);
		if (count == chunk_size || is_empty(a))
		{
			curr_max += chunk_size;
			count = 0;
		}
	}
	fill_back_to_a(a, b, ops);
}
