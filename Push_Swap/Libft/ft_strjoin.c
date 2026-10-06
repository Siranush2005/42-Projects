/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:41:16 by sarakely          #+#    #+#             */
/*   Updated: 2026/02/03 13:41:16 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*joint_string;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	joint_string = (char *)malloc(size_s1 + size_s2 + 1);
	if (!joint_string)
		return (NULL);
	ft_strlcpy(joint_string, s1, size_s1 + 1);
	ft_strlcpy(joint_string + size_s1, s2, size_s2 + 1);
	return (joint_string);
}
//ft_strlcat(joint_string, s2, size_s1 + size_s2 + 1);
// kam el sa 2rd angam ft_strlcpy funkcia kanchelu texy
/*
int	main(void)
{
	char	*str;

	str = ft_strjoin("Hello", " World!");
	printf("%s\n", str);
	return (0);
}
*/
