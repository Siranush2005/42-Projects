/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_top_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:43:50 by sarakely          #+#    #+#             */
/*   Updated: 2026/04/27 14:02:54 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_stack *stack)
{
	int	temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	temp = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = temp;
	temp = stack->top->index;
	stack->top->index = stack->top->next->index;
	stack->top->next->index = temp;
}

void	sa(t_stack *a, t_ops *ops)
{
	swap_top(a);
	write(1, "sa\n", 3);
	if (ops)
	{
		ops->sa++;
		ops->total++;
	}
}

void	sb(t_stack *b, t_ops *ops)
{
	swap_top(b);
	write(1, "sb\n", 3);
	if (ops)
	{
		ops->sb++;
		ops->total++;
	}
}

void	ss(t_stack *a, t_stack *b, t_ops *ops)
{
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
	if (ops)
	{
		ops->ss++;
		ops->total++;
	}
}
