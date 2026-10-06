/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 00:00:00 by sarakely          #+#    #+#             */
/*   Updated: 2026/05/01 19:07:08 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(int argc, char **argv, int start)
{
	char	*result;
	char	*temp;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = start;
	while (i < argc)
	{
		temp = ft_strjoin(result, argv[i]);
		free(result);
		if (!temp)
			return (NULL);
		result = temp;
		if (i++ < argc - 1)
		{
			temp = ft_strjoin(result, " ");
			free(result);
			if (!temp)
				return (NULL);
			result = temp;
		}
	}
	return (result);
}

static int	check_flag(char *arg, t_config *cfg)
{
	if (!ft_strncmp(arg, "--simple", 9))
		return (cfg->strategy = 0, 1);
	if (!ft_strncmp(arg, "--medium", 9))
		return (cfg->strategy = 1, 1);
	if (!ft_strncmp(arg, "--complex", 10))
		return (cfg->strategy = 2, 1);
	if (!ft_strncmp(arg, "--adaptive", 11))
		return (cfg->strategy = 3, 1);
	if (!ft_strncmp(arg, "--bench", 8))
		return (cfg->bench = 1, 1);
	if (!ft_strncmp(arg, "--count-only", 13))
		return (cfg->count_only = 1, 1);
	return (0);
}

t_stack	*setup_stacks(int argc, char **argv, t_config *cfg)
{
	int		i;
	char	*joined;
	t_stack	*a;

	cfg->strategy = 3;
	cfg->bench = 0;
	cfg->count_only = 0;
	i = 1;
	while (i < argc && check_flag(argv[i], cfg))
		i++;
	if (i >= argc)
		return (NULL);
	joined = join_args(argc, argv, i);
	if (!joined)
		return (NULL);
	a = parse_input(joined);
	free(joined);
	if (!a)
		write(2, "Error\n", 6);
	return (a);
}
