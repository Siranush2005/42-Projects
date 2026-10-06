/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:09:33 by sarakely          #+#    #+#             */
/*   Updated: 2026/03/24 16:57:52 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *s)
{
	char	*newline_ptr;
	char	*line;

	if (!s || !*s)
		return (NULL);
	newline_ptr = ft_strchr(s, '\n');
	if (!newline_ptr)
		return (ft_strdup(s));
	line = (char *)malloc(newline_ptr - s + 2);
	if (!line)
		return (NULL);
	ft_strlcpy(line, s, newline_ptr - s + 2);
	return (line);
}

char	*clean_storage(char *s)
{
	char	*newline;
	char	*new_storage;

	newline = ft_strchr(s, '\n');
	if (!newline)
	{
		free(s);
		return (NULL);
	}
	new_storage = ft_strdup(newline + 1);
	free(s);
	return (new_storage);
}

char	*read_and_join(int fd, char *storage)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(storage, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buffer), free(storage), NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(storage, buffer);
		free(storage);
		storage = tmp;
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	storage = read_and_join(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	storage = clean_storage(storage);
	return (line);
}
