/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:35:21 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:06:47 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	calculate_disorder(t_stack *a, t_ops *ops)
{
	int				mistakes;
	int				total_pairs;
	t_stack_node	*i;
	t_stack_node	*j;

	if (a->size <= 1)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	ops->disorder = (double)mistakes / (double)total_pairs;
	return (ops->disorder);
}
