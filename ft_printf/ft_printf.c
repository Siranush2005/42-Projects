/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:41:50 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/27 14:35:11 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specificator(char ch, va_list *arg_ptr)
{
	int	count;

	count = 0;
	if (ch == 'c')
		count = ft_print_char(va_arg(*arg_ptr, int));
	else if (ch == 's')
		count = ft_print_string(va_arg(*arg_ptr, char *));
	else if (ch == 'p')
		count = ft_print_pointer(va_arg(*arg_ptr, void *));
	else if (ch == 'd' || ch == 'i')
		count = ft_print_int_or_dec(va_arg(*arg_ptr, int));
	else if (ch == 'u')
		count = ft_print_unsigned_dec(va_arg(*arg_ptr, unsigned int));
	else if (ch == 'x')
		count = ft_print_hex_lowercase(va_arg(*arg_ptr, unsigned int));
	else if (ch == 'X')
		count = ft_print_hex_uppercase(va_arg(*arg_ptr, unsigned int));
	else if (ch == '%')
		count = ft_print_percent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
			count += check_specificator(*(++str), &args);
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
