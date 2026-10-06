/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 19:00:40 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:00:40 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"

typedef struct s_stack_node
{
	int						value;
	int						index;
	struct s_stack_node		*next;
}	t_stack_node;

typedef struct s_stack
{
	int				size;
	t_stack_node	*top;
}	t_stack;

typedef struct s_ops
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	double	disorder;
}	t_ops;

typedef struct s_config
{
	int	strategy;
	int	bench;
	int	count_only;
}	t_config;

t_stack_node	*create_node(int val);
void			ft_push(t_stack *stack, t_stack_node *new_node);
t_stack_node	*ft_pop(t_stack *stack);
void			free_stack(t_stack *stack);
int				is_empty(t_stack *stack);

t_stack			*parse_input(char *str);
void			free_split(char **split);

void			indexing(t_stack *stack);

int				get_min_pos(t_stack *stack);
int				get_max_pos(t_stack *stack);

int				is_sorted(t_stack *a, t_stack *b);

double			calculate_disorder(t_stack *a, t_ops *ops);

void			init_ops(t_ops *ops);
void			init_config(t_config *cfg);

void			swap_top(t_stack *stack);
void			sa(t_stack *a, t_ops *ops);
void			sb(t_stack *b, t_ops *ops);
void			ss(t_stack *a, t_stack *b, t_ops *ops);

void			push_to_stacks(t_stack *first, t_stack *second);
void			pa(t_stack *a, t_stack *b, t_ops *ops);
void			pb(t_stack *a, t_stack *b, t_ops *ops);

void			rotate_stacks(t_stack *stack);
void			ra(t_stack *a, t_ops *ops);
void			rb(t_stack *b, t_ops *ops);
void			rr(t_stack *a, t_stack *b, t_ops *ops);

void			rev_rotate_stacks(t_stack *stack);
void			rra(t_stack *a, t_ops *ops);
void			rrb(t_stack *b, t_ops *ops);
void			rrr(t_stack *a, t_stack *b, t_ops *ops);

void			sorting_2_items(t_stack *a, t_ops *ops);
void			sorting_3_items(t_stack *a, t_ops *ops);
void			sorting_5_items(t_stack *a, t_stack *b, t_ops *ops);

void			simple_sort(t_stack *a, t_stack *b, t_ops *ops);
void			medium_sort(t_stack *a, t_stack *b, t_ops *ops);
void			complex_sort(t_stack *a, t_stack *b, t_ops *ops);
void			adaptive_sort(t_stack *a, t_stack *b, t_ops *ops);

t_stack			*setup_stacks(int argc, char **argv, t_config *cfg);

void			print_benchmark(t_ops *ops, int strategy);
#endif