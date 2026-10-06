/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:08:32 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:06:43 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bit_count(int n)
{
	int	bits;

	bits = 0;
	while (n >> bits)
		bits++;
	return (bits);
}

void	complex_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	max_bits;
	int	bit;
	int	i;
	int	size;

	size = a->size;
	max_bits = max_bit_count(size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if ((a->top->index >> bit) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			i++;
		}
		while (!is_empty(b))
			pa(a, b, ops);
		bit++;
	}
}
