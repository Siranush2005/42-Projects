/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isValidInput.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:40:21 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:40:13 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_num(const char *str, long *result)
{
	long	num;
	int		sign;

	if (!str || !*str)
		return (0);
	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		num = num * 10 + (*str++ - '0');
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (0);
	}
	*result = num * sign;
	return (1);
}

static int	has_duplicate_in_stack(t_stack *stack, int val)
{
	t_stack_node	*temp;

	temp = stack->top;
	while (temp)
	{
		if (temp->value == val)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static int	filling_stack(t_stack *stack, char **split)
{
	long			num;
	int				i;
	t_stack_node	*node;

	if (!stack || !split || !*split)
		return (0);
	i = 0;
	while (split[i])
		i++;
	while (i--)
	{
		if (!is_valid_num(split[i], &num))
			return (0);
		if (has_duplicate_in_stack(stack, (int)num))
			return (0);
		node = create_node((int)num);
		if (!node)
			return (0);
		ft_push(stack, node);
	}
	return (1);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

t_stack	*parse_input(char *str)
{
	char		**splitted_input;
	t_stack		*stack;

	if (!str || !*str)
		return (NULL);
	splitted_input = ft_split(str, ' ');
	if (!splitted_input || !*splitted_input)
		return (free_split(splitted_input), (NULL));
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (free_split(splitted_input), NULL);
	stack->top = NULL;
	stack->size = 0;
	if (!filling_stack(stack, splitted_input))
	{
		free_split(splitted_input);
		free_stack(stack);
		free(stack);
		return (NULL);
	}
	free_split(splitted_input);
	return (stack);
}
