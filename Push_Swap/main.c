/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:07:19 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:07:19 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_stack *a, t_stack *b, t_ops *ops, int strategy)
{
	if (strategy == 0)
		simple_sort(a, b, ops);
	else if (strategy == 1)
		medium_sort(a, b, ops);
	else if (strategy == 2)
		complex_sort(a, b, ops);
	else
		adaptive_sort(a, b, ops);
}

static void	print_count(t_ops *ops)
{
	ft_putnbr_fd(ops->total, 1);
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_ops		ops;
	t_config	cfg;

	if (argc < 2)
		return (0);
	a = setup_stacks(argc, argv, &cfg);
	if (!a)
		return (1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (free_stack(a), free(a), 1);
	b->top = NULL;
	b->size = 0;
	indexing(a);
	init_ops(&ops);
	if (!is_sorted(a, b))
		run_sort(a, b, &ops, cfg.strategy);
	if (cfg.count_only)
		print_count(&ops);
	if (cfg.bench)
		print_benchmark(&ops, cfg.strategy);
	return (free_stack(a), free(a), free_stack(b), free(b), 0);
}
