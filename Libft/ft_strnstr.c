/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:41:57 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/07 15:15:33 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	if (!big)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = 0;
	while (i < n && big[i])
	{
		j = 0;
		while (i + j < n && big[i + j] && big[i + j] == little[j])
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

/*

int main(void)
{
	printf("%s\n", ft_strnstr("hello", "", 5)); // should return "hello"
	printf("%s\n", ft_strnstr("hi", "hello", 5)); // should return NULL
	printf("%s\n", ft_strnstr("hello", "hello world", 5)); // should return NULL
	printf("%s\n", ft_strnstr("hello world", "hello", 11)); 
	// returns pointer to "hello world"
	printf("%s\n", ft_strnstr("hello world", "world", 5)); // returns NULL
	printf("%s\n", ft_strnstr("abcdxyz", "cd", 5)); // returns pointer to "cdxyz"
	printf("%s\n", ft_strnstr("aaaaa", "a", 5));
	// should return pointer to first "a"
	printf("%s\n", ft_strnstr("hello", "z", 5)); // should return NULL
	return (0);
}

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	char	*ptr_little_in_big;
	char	*ptr_little;

	if (!*little)
		return ((char *)big);

	while (n && *big)
	{
		if (*big == *little)
		{
			ptr_little_in_big = (char *)big;
			ptr_little = (char *)little;
			size_t temp_n = n;

			while (temp_n && *big && *big == *ptr_little)
			{
				big++;
				ptr_little++;
				temp_n--;
			}
			if (*ptr_little == '\0')
				return (ptr_little_in_big);
			big = ptr_little_in_big; // restore big for outer loop
		}
		big++;
		n--;
	}
	return (NULL);
}
*/
