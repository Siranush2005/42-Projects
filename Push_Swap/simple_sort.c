/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:13:25 by sarakely          #+#    #+#             */
/*   Updated: 2026/04/29 16:11:39 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	int	min_pos;
	int	bottom_pos;

	while (!is_empty(a))
	{
		min_pos = get_min_pos(a);
		if (min_pos <= a->size / 2)
			while (min_pos--)
				ra(a, ops);
		else
		{
			bottom_pos = a->size - min_pos;
			while (bottom_pos--)
				rra(a, ops);
		}
		pb(a, b, ops);
	}
	while (!is_empty(b))
		pa(a, b, ops);
}
