/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:20:55 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/26 13:28:14 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_char(char ch);
int	ft_print_int_or_dec(int num);
int	ft_print_percent(void);
int	ft_print_pointer(void *ptr);
int	ft_print_string(char *str);
int	ft_print_unsigned_dec(unsigned int num);
int	ft_print_hex_lowercase(unsigned long num);
int	ft_print_hex_uppercase(unsigned long num);

#endif
