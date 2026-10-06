/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:59:59 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/05 18:55:15 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ??
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*start_dest;
	unsigned char	*start_src;

	if (!dest)
		return (NULL);
	if (!src)
		return (dest);
	if (!n)
		return (dest);
	start_dest = (unsigned char *)dest;
	start_src = (unsigned char *)src;
	while (n--)
		*start_dest++ = *start_src++;
	return (dest);
}
