/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:40:53 by sarakely          #+#    #+#             */
/*   Updated: 2026/04/30 15:23:43 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*create_node(int val)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return (NULL);
	new_node->value = val;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_push(t_stack *stack, t_stack_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

t_stack_node	*ft_pop(t_stack *stack)
{
	t_stack_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	stack->size--;
	node->next = NULL;
	return (node);
}

void	free_stack(t_stack *stack)
{
	t_stack_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->size = 0;
}

int	is_empty(t_stack *stack)
{
	return (!stack || !stack->top);
}
