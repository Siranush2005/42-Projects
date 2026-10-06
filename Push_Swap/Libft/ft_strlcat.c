/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:47:41 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/06 16:41:06 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	index;
	size_t	init_dest_size;
	size_t	src_size;

	init_dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (n <= init_dest_size)
		return (n + src_size);
	index = 0;
	while (src[index] && (init_dest_size + index) < n - 1)
	{
		dest[init_dest_size + index] = src[index];
		index++;
	}
	dest[init_dest_size + index] = '\0';
	return (init_dest_size + src_size);
}
