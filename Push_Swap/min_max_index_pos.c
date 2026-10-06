/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_index_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 14:50:50 by sarakely          #+#    #+#             */
/*   Updated: 2026/04/30 12:28:46 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_stack *stack)
{
	t_stack_node	*temp;
	int				min;
	int				min_pos;
	int				pos;

	if (!stack || !stack->top)
		return (-1);
	temp = stack->top;
	min = temp->index;
	min_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index < min)
		{
			min = temp->index;
			min_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (min_pos);
}

int	get_max_pos(t_stack *stack)
{
	t_stack_node	*temp;
	int				max;
	int				max_pos;
	int				pos;

	if (!stack || !stack->top)
		return (-1);
	temp = stack->top;
	max = temp->index;
	max_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index > max)
		{
			max = temp->index;
			max_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (max_pos);
}
