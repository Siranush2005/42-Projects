/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:30:11 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:01:55 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack *a, t_stack *b, t_ops *ops)
{
	if (!a || !ops || a->size <= 1)
		return ;
	ops->disorder = calculate_disorder(a, ops);
	if (a->size == 2)
		return (sorting_2_items(a, ops));
	if (a->size == 3)
		return (sorting_3_items(a, ops));
	if (a->size <= 5)
		return (sorting_5_items(a, b, ops));
	if (ops->disorder < 0.2)
		simple_sort(a, b, ops);
	else if (ops->disorder < 0.5)
		medium_sort(a, b, ops);
	else
		complex_sort(a, b, ops);
}
