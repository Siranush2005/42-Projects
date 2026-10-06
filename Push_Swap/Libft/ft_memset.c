/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:20:39 by sarakely          #+#    #+#             */
/*   Updated: 2026/01/29 16:03:19 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char	*start;

	start = ptr;
	while (n--)
		*start++ = (unsigned char)x;
	return (ptr);
}
/*
int	main(void)
{
	char	str[20] = "Hello World";

	ft_memset(str, '7', 2);
	//poxum e byte ar byte, int type-i zangvaci depqum ayl ardyunq kta
	printf("%s\n", str);
	return (0);
}*/
