/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:28:29 by sarakely          #+#    #+#             */
/*   Updated: 2026/04/27 14:08:52 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stacks(t_stack *stack)
{
	t_stack_node	*prev_head;
	t_stack_node	*temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	prev_head = stack->top;
	stack->top = stack->top->next;
	prev_head->next = NULL;
	temp = stack->top;
	while (temp->next)
		temp = temp->next;
	temp->next = prev_head;
}

void	ra(t_stack *a, t_ops *ops)
{
	rotate_stacks(a);
	write(1, "ra\n", 3);
	if (ops)
	{
		ops->ra++;
		ops->total++;
	}
}

void	rb(t_stack *b, t_ops *ops)
{
	rotate_stacks(b);
	write(1, "rb\n", 3);
	if (ops)
	{
		ops->rb++;
		ops->total++;
	}
}

void	rr(t_stack *a, t_stack *b, t_ops *ops)
{
	rotate_stacks(a);
	rotate_stacks(b);
	write(1, "rr\n", 3);
	if (ops)
	{
		ops->rr++;
		ops->total++;
	}
}
