/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:28:30 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/03 13:28:30 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// The 32th line is there to avoid comparing
// with an uninitialized variable on line 37.

static void	fill_string(char *str, int n, int index)
{
	int	pos_or_neg;

	pos_or_neg = 1;
	if (n < 0)
	{
		pos_or_neg = -1;
		str[index + 1] = '\0';
		str[0] = '-';
	}
	else
	{
		str[index--] = '\0';
		str[0] = '0';
	}
	while (index)
	{
		str[index--] = n % 10 * pos_or_neg + '0';
		n /= 10;
	}
	if (str[0] == '-')
		return ;
	str[0] = n % 10 * pos_or_neg + '0';
}

char	*ft_itoa(int n)
{
	int		digit_len;
	int		temp_n;
	char	*str;

	digit_len = 0;
	temp_n = n;
	if (temp_n == 0)
		digit_len = 1;
	while (temp_n)
	{
		digit_len++;
		temp_n /= 10;
	}
	if (n < 0)
		str = (char *)malloc(digit_len + 2);
	else
		str = (char *)malloc(digit_len + 1);
	if (!str)
		return (NULL);
	fill_string(str, n, digit_len);
	return (str);
}
/*
int	main(void)
{
	char	*num;

	num = ft_itoa(-2147483648);
	printf("%s\n", num);
	free(num);
	return (0);
}
*/
