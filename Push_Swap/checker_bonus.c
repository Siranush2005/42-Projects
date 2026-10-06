/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:53:28 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:06:38 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exec_op(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (swap_top(a), 1);
	if (!ft_strncmp(line, "sb\n", 3))
		return (swap_top(b), 1);
	if (!ft_strncmp(line, "ss\n", 3))
		return (swap_top(a), swap_top(b), 1);
	if (!ft_strncmp(line, "pa\n", 3))
		return (push_to_stacks(a, b), 1);
	if (!ft_strncmp(line, "pb\n", 3))
		return (push_to_stacks(b, a), 1);
	if (!ft_strncmp(line, "ra\n", 3))
		return (rotate_stacks(a), 1);
	if (!ft_strncmp(line, "rb\n", 3))
		return (rotate_stacks(b), 1);
	if (!ft_strncmp(line, "rr\n", 3))
		return (rotate_stacks(a), rotate_stacks(b), 1);
	if (!ft_strncmp(line, "rra\n", 4))
		return (rev_rotate_stacks(a), 1);
	if (!ft_strncmp(line, "rrb\n", 4))
		return (rev_rotate_stacks(b), 1);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (rev_rotate_stacks(a), rev_rotate_stacks(b), 1);
	return (0);
}

static void	free_and_error(t_stack *a, t_stack *b, char *line)
{
	free_stack(a);
	free(a);
	free_stack(b);
	free(b);
	free(line);
	write(2, "Error\n", 6);
	exit(1);
}

static void	process_input(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!exec_op(line, a, b))
			free_and_error(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

static t_stack	*init_b(t_stack *a)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
	{
		free_stack(a);
		free(a);
		return (NULL);
	}
	b->top = NULL;
	b->size = 0;
	return (b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	cfg;

	if (argc < 2)
		return (0);
	a = setup_stacks(argc, argv, &cfg);
	if (!a)
		return (1);
	b = init_b(a);
	if (!b)
		return (1);
	process_input(a, b);
	if (is_sorted(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(a), free(a), free_stack(b), free(b), 0);
}
