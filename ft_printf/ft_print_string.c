/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:00:49 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/26 16:57:06 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
		len += write(1, str++, 1);
	return (len);
}
