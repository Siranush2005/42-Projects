/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:27:07 by sarakely          #+#    #+#             */
/*   Updated: 2026/01/29 16:13:16 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int x)
{
	const char	*found_ptr;

	found_ptr = str;
	while (*found_ptr && *found_ptr != (unsigned char)x)
		found_ptr++;
	if (*found_ptr == (unsigned char)x)
		return ((char *)found_ptr);
	return (NULL);
}
