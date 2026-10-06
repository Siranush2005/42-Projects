/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:25:25 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/26 16:26:49 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
//strchr-ov kam strrchr-ov shat karch kareli a grel
static int	count_word(char const *s, char c)
{
	int	count;
	int	word_flag;

	count = 0;
	while (*s)
	{
		word_flag = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			word_flag = 1;
			s++;
		}
		if (word_flag)
			count++;
	}
	return (count);
}

// static int	count_word(char const *s, char c)
// {
// 	int	count;

// 	count = 0;
// 	while (*s)
// 	{
// 		while (*s && *s == c)
// 			s++;
// 		if (*s)
// 			count++;
// 		while (*s && *s != c)
// 			s++;
// 	}
// 	return (count);
// }

static char	**free_string(char **split, int i)
{
	while (i >= 0)
		free(split[i--]);
	free(split);
	return (NULL);
}

static char	**filling_splitted(char **split, char const *s, char c)
{
	int			i;
	const char	*start;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i] = ft_substr(start, 0, s - start);
			if (!split[i])
				return (free_string(split, i - 1));
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	splitted = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!splitted)
		return (NULL);
	return (filling_splitted(splitted, s, c));
}
/*
int	main(void)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split("  42 school  is  cool  ", ' ');
	if (!tab)
	{
		printf("Split returned NULL\n");
		return (1);
	}
	while (tab[i])
	{
		printf("Word [%d]: %s\n", i, tab[i]);
		free(tab[i++]);
	}
	free(tab);
	return (0);
}
*/
