/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:03:37 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/03 13:47:42 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>
//??
//kara senc lini ((!dest && !src) || !dest) 27rd tox
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*_dest;
	const unsigned char	*_src;

	if (!dest && !src)
		return (NULL);
	if (dest && !src)
		return (dest);
	if (!dest)
		return (NULL);
	_dest = (unsigned char *)dest;
	_src = (const unsigned char *)src;
	if (_dest < _src)
		while (n--)
			*_dest++ = *_src++;
	else
		while (n--)
			_dest[n] = _src[n];
	return (dest);
}
/*
int	main(void)
{
    char str1[20] = "HelloWorld";

    printf("Before memmove: %s\n", str1);
    ft_memmove(str1, str1 + 5, 5); 
   // str1[5] = '\0'; 
    printf("After ft_memmove: %s\n", str1);

    char str2[20] = "HelloWorld";
    memmove(str2, str2 + 5, 5);
   // str2[5] = '\0';
    printf("After memmove: %s\n\n", str2);

	char str3[20] = "HelloWorld";
	printf("Before memmove: %s\n", str1);
    ft_memmove(str1 + 5, str1, 5); 
    printf("After ft_memmove: %s\n", str3);

    char str4[20] = "HelloWorld";
	printf("Before memmove: %s\n", str4);
    memmove(str4 + 5, str4, 5);
    printf("After memmove: %s\n\n", str4);
    return (0);
}*/