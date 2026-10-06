/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:25:42 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/26 13:07:06 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	unsigned long	p;

	if (!ptr)
		return (write(1, "(nil)", 5));
	p = (unsigned long)ptr;
	return (write(1, "0x", 2) + ft_print_hex_lowercase(p));
}
