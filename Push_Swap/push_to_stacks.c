/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:57:50 by sarakely          #+#    #+#             */
/*   Updated: 2026/10/06 16:52:53 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push_to_stacks is used for the bonus, so operations are not written here.

void	push_to_stacks(t_stack *first, t_stack *second)
{
	t_stack_node	*node;

	if (!second || !second->top)
		return ;
	node = ft_pop(second);
	if (!node)
		return ;
	ft_push(first, node);
}

void	pa(t_stack *a, t_stack *b, t_ops *ops)
{
	t_stack_node	*node;

	if (!b || !b->top)
		return ;
	node = ft_pop(b);
	if (!node)
		return ;
	ft_push(a, node);
	write(1, "pa\n", 3);
	if (ops)
	{
		ops->pa++;
		ops->total++;
	}
}

void	pb(t_stack *a, t_stack *b, t_ops *ops)
{
	t_stack_node	*node;

	if (!a || !a->top)
		return ;
	node = ft_pop(a);
	if (!node)
		return ;
	ft_push(b, node);
	write(1, "pb\n", 3);
	if (ops)
	{
		ops->pb++;
		ops->total++;
	}
}
