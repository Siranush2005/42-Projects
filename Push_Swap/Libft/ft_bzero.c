/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:57:41 by sarakely          #+#    #+#             */
/*   Updated: 2026/01/29 16:00:21 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_bzero(void *ptr, size_t n)
{
	unsigned char	*start;

	start = ptr;
	while (n--)
		*start++ = 0;
}
/*
int	main(void)
{
	char	str[20] = "Hello World";
	int		arr1[5] = { 1, 2, 3, 4, 5 };
	int		arr2[5] = { 100000, 1, 2, 3, 4 };
	int		i;

	ft_memset(str, 48, 2);
	printf("%s\n", str);
	ft_memset(str, 5, 2);
	printf("%s\n", str);
	ft_memset(arr1, 5, 2);
	i = -1;
	while (++i < 5)
		printf("%d ", arr1[i]);
	printf("\n");
	ft_memset(arr2, 5, 2);
	i = -1;
	while (++i < 5)
		printf("%d ", arr2[i]);
	printf("\n");
	return (0);
}
*/
