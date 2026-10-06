/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:53:39 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/07 15:16:55 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	remove_front_index(const char *s1, const char *set);
static int	comparison_with_set_symbols(const char *ch, const char *set);
static int	remove_back_index(const char *s1, const char *set);

static int	remove_front_index(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i] && comparison_with_set_symbols(&s1[i], set))
		i++;
	return (--i);
}

static int	comparison_with_set_symbols(const char *ch, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (*ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	remove_back_index(const char *s1, const char *set)
{
	int	i;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && comparison_with_set_symbols(&s1[i], set))
		i--;
	return (++i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front_index;
	int		back_index;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front_index = remove_front_index(s1, set);
	back_index = remove_back_index(s1, set);
	if (front_index >= back_index)
		return (ft_strdup(""));
	return (ft_substr(s1, front_index + 1, back_index - front_index - 1));
}
/* (kam sa` 65rd toxi poxaren)
trimmedstr = malloc(back_index - front_index);
if (!trimmedstr)
	return (NULL);
i = 0;
while (++front_index < back_index)
	trimmedstr[i++] = s1[front_index];
trimmedstr[i] = '\0';
return (trimmedstr);
*/
/*
int	main(void)
{
	char	*str;

	str = ft_strtrim("1234abcd1234", "1234");
	printf("%s\n", str);
	free(str);

	str = ft_strtrim("1234abcd1234", "1234");
	printf("%s\n", str); free(str);

	str = ft_strtrim("abcd", "1234");
	printf("%s\n", str); free(str);

	str = ft_strtrim("1234abcd", "1234");
	printf("%s\n", str); free(str);

	str = ft_strtrim("abcd1234", "1234");
	printf("%s\n", str); free(str);

	str = ft_strtrim("aaaa", "a");
	printf("%s\n", str); free(str);

	str = ft_strtrim("1234", "1234");
	printf("%s\n", str); free(str);

	str = ft_strtrim("ababab", "ab");
	printf("%s\n", str); free(str);

	str = ft_strtrim("hello", "xyz");
	printf("%s\n", str); free(str);

	str = ft_strtrim("42", "abc");
	printf("%s\n", str); free(str);

	str = ft_strtrim("test", "");
	printf("%s\n", str); free(str);

	str = ft_strtrim("a", "a");
	printf("%s\n", str); free(str);

	str = ft_strtrim("a", "b");
	printf("%s\n", str); free(str);

	str = ft_strtrim("", "a");
	printf("%s\n", str); free(str);

	str = ft_strtrim("", "");
	printf("%s\n", str); free(str);

	str = ft_strtrim("aaabaaa", "a");
	printf("%s\n", str); free(str);

	str = ft_strtrim("xxhelloxx", "x");
	printf("%s\n", str); free(str);

	str = ft_strtrim("111abc111def111", "1");
	printf("%s\n", str); free(str);

	str = ft_strtrim(" \t\nhello \n\t", " \n\t");
	printf("%s\n", str); free(str);

	str = ft_strtrim("--++42++--", "+-");
	printf("%s\n", str); free(str);

	str = ft_strtrim("abcXYZabc", "abc");
	printf("%s\n", str); free(str);

	str = ft_strtrim("ahello", "a");
	printf("%s\n", str); free(str);

	str = ft_strtrim("helloa", "a");
	printf("%s\n", str); free(str);

	str = ft_strtrim("a", "");
	printf("%s\n", str); free(str);

	str = ft_strtrim("a", "aa");
	printf("%s\n", str); free(str);

	return (0);
}
*/
