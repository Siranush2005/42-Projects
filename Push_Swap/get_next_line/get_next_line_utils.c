/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:10:21 by sarakely          #+#    #+#             */
/*   Updated: 2026/03/23 18:23:05 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int x)
{
	const char	*found_ptr;

	found_ptr = str;
	while (*found_ptr && *found_ptr != (unsigned char)x)
		found_ptr++;
	if (*found_ptr == (unsigned char)x)
		return ((char *)found_ptr);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(str) + 1;
	ptr = (char *)malloc(size);
	if (ptr)
	{
		while (size--)
			*(ptr + size) = *(str + size);
		return (ptr);
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (!n)
		return (ft_strlen(src));
	while (i < n - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

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
