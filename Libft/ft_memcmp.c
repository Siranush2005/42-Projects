/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:40:08 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/03 13:40:08 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_1;
	const unsigned char	*ptr_2;

	ptr_1 = (const unsigned char *)s1;
	ptr_2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ptr_1 != *ptr_2)
			return (*ptr_1 - *ptr_2);
		ptr_1++;
		ptr_2++;
	}
	return (0);
}
/*
int main(void)
{
	char a[] = {7, 2, 3};
	char b[] = {7, 2, 4};

	printf("%d\n", ft_memcmp(a, b, 1));
	printf("%d\n", ft_memcmp(a, b, 2));
	printf("%d\n", ft_memcmp(a, a, 3)); //
	return (0);
}
*/