/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 15:27:56 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 20:11:09 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*strategy_name(double disorder, int strategy)
{
	char	*adaptive;

	if (strategy == 0)
		return ("Simple / O(n^2)\n");
	if (strategy == 1)
		return ("Medium / O(n*sqrt(n))\n");
	if (strategy == 2)
		return ("Complex / O(n log n)\n");
	if (disorder < 0.2)
		adaptive = "Adaptive / O(n^2)\n";
	else if (disorder < 0.5)
		adaptive = "Adaptive / O(n*sqrt(n))\n";
	else
		adaptive = "Adaptive / O(n log n)\n";
	return (adaptive);
}

static void	print_disorder(double disorder)
{
	int		int_part;
	int		frac_part;
	double	percent;

	percent = disorder * 100.0;
	int_part = (int)percent;
	frac_part = (int)((percent - int_part) * 100);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putchar_fd('.', 2);
	if (frac_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(frac_part, 2);
	ft_putchar_fd('%', 2);
	ft_putchar_fd('\n', 2);
}

static void	print_ops_numbers(t_ops *ops)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(ops->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(ops->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(ops->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(ops->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(ops->pb, 2);
	write(2, "\n", 1);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(ops->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(ops->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(ops->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(ops->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(ops->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(ops->rrr, 2);
	write(2, "\n", 1);
}

void	print_benchmark(t_ops *ops, int strategy)
{
	print_disorder(ops->disorder);
	if (!ops->total)
		ft_putstr_fd("[bench] strategy: No strategy\n", 2);
	else
	{
		ft_putstr_fd("[bench] strategy: ", 2);
		ft_putstr_fd(strategy_name(ops->disorder, strategy), 2);
	}
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(ops->total, 2);
	ft_putchar_fd('\n', 2);
	print_ops_numbers(ops);
}
