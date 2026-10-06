/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:05:50 by sarakely          #+#    #+#             */
/*   Updated: 2026/01/29 16:45:07 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//???
#include "libft.h"

char	*ft_strrchr(const char *str, int x)
{
	const char	*found_ptr;

	found_ptr = NULL;
	while (*str)
	{
		if (*str == (unsigned char)x)
			found_ptr = (char *)str;
		str++;
	}
	if (*str == x)
		return ((char *)str);
	return ((char *)found_ptr);
}
// kam ogtagorcel ft_strlen u verjic stugel (u chogtagorcel found_ptr)
/*
 ft_strrchr("hello", 'h');   // points to 'h'
ft_strrchr("hello", 'l');   // points to second 'l'
ft_strrchr("hello", 'o');   // points to 'o'
ft_strrchr("hello", 'x');   // NULL
ft_strrchr("hello", '\0');  // pointer to '\0'
ft_strrchr("", '\0');       // pointer to '\0'
ft_strrchr("", 'a');        // NULL
*/
