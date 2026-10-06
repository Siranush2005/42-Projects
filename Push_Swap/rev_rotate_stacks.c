/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:39:52 by sarakely          #+#    #+#             */
/*   Updated: 2026/04/27 14:28:05 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stacks(t_stack *stack)
{
	t_stack_node	*prev_head;
	t_stack_node	*new_head;
	t_stack_node	*temp;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	prev_head = stack->top;
	temp = stack->top;
	while (temp->next->next)
		temp = temp->next;
	new_head = temp->next;
	temp->next = NULL;
	stack->top = new_head;
	new_head->next = prev_head;
}

void	rra(t_stack *a, t_ops *ops)
{
	rev_rotate_stacks(a);
	write(1, "rra\n", 4);
	if (ops)
	{
		ops->rra++;
		ops->total++;
	}
}

void	rrb(t_stack *b, t_ops *ops)
{
	rev_rotate_stacks(b);
	write(1, "rrb\n", 4);
	if (ops)
	{
		ops->rrb++;
		ops->total++;
	}
}

void	rrr(t_stack *a, t_stack *b, t_ops *ops)
{
	rev_rotate_stacks(a);
	rev_rotate_stacks(b);
	write(1, "rrr\n", 4);
	if (ops)
	{
		ops->rrr++;
		ops->total++;
	}
}
