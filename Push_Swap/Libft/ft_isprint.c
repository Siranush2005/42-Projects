/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:12:34 by sarakely          #+#    #+#             */
/*   Updated: 2026/01/29 16:02:19 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <unistd.h>

int	ft_isprint(int ch)
{
	if (ch > 31 && ch < 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	x;

	x = ft_isprint('	') + '0';
	write(1, &x, 1);
	write(1, "\n", 1);
	x = ft_isprint(' ') + '0';
	write(1, &x, 1);
	write(1, "\n", 1);
	x = ft_isprint('\n') + '0';
	write(1, &x, 1);
	write(1, "\n", 1);
	x = ft_isprint('5') + '0';
	write(1, &x, 1);
	write(1, "\n", 1);
	return (0);
}
*/
