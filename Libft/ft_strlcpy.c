/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:07:18 by sarakely          #+#    #+#             */
/*   Updated: 2026/10/06 16:39:50 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (!n)
		return (ft_strlen(src));
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int main(void)
{
    char buf[10];

    printf("%zu\n", ft_strlcpy(buf, "Hello", 6));  
    printf("%s\n", buf);

    printf("%zu\n", ft_strlcpy(buf, "Hello", 3));
    printf("%s\n", buf);

    printf("%zu\n", ft_strlcpy(buf, "Hello", 0));

    printf("%zu\n", ft_strlcpy(NULL, "Hello", 0)); 

    printf("%zu\n", ft_strlcpy(NULL, "Hello", 4)); 

    printf("%zu\n", ft_strlcpy(buf, "", 5));       
    printf("%s\n", buf);

    printf("%zu\n", ft_strlcpy(buf, "Hi", 10));  
    printf("%s\n", buf);

    printf("%zu\n", ft_strlcpy(buf, "ABCDE", 1));  
    printf("%s\n", buf);
}*/
