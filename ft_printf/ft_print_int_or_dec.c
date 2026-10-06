/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_or_dec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:00:14 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/26 14:13:39 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	ft_print_int_or_dec(int num)
{
	int	len;

	len = 0;
	if (!num)
		return (write(1, "0", 1));
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		num = -num;
		len += write(1, "-", 1);
	}
	if (num > 9)
		len += ft_print_int_or_dec(num / 10);
	ft_putchar(num % 10 + '0');
	len++;
	return (len);
}
// len += write(1, &"0123456789"[nb % 10], 1);