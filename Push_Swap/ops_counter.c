/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_counter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:09:53 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:09:53 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ops(t_ops *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->total = 0;
}

void	init_config(t_config *cfg)
{
	cfg->strategy = 3;
	cfg->bench = 0;
	cfg->count_only = 0;
}
