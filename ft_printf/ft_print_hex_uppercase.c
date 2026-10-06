/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_uppercase.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:25:09 by sarakely          #+#    #+#             */
/*   Updated: 2026/10/06 16:57:29 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar_hex(unsigned long hex_digit)
{
	char	*hex_str;

	hex_str = "0123456789ABCDEF";
	write(1, hex_str + hex_digit, 1);
	return (1);
}

int	ft_print_hex_uppercase(unsigned long num)
{
	int	count;

	count = 0;
	if (num > 15)
		count += ft_print_hex_uppercase(num / 16);
	count += ft_putchar_hex(num % 16);
	return (count);
}
