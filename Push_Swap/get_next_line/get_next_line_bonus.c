/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarakely <sarakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 17:08:55 by sarakely          #+#    #+#             */
/*   Updated: 2026/03/24 16:38:03 by sarakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*extract_line(char *s)
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

static char	*clean_storage(char *s)
{
	char	*newline;
	char	*new_storage;

	newline = ft_strchr(s, '\n');
	if (!newline || !*(newline + 1))
	{
		free(s);
		return (NULL);
	}
	new_storage = ft_strdup(newline + 1);
	free(s);
	return (new_storage);
}

static char	*read_and_join(int fd, char *storage)
{
	char	*buffer;
	char	*tmp;
	int		bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(storage), NULL);
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
		if (!storage)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char		*storage[1024];
	char			*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	if (!storage[fd])
		return (NULL);
	storage[fd] = read_and_join(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = extract_line(storage[fd]);
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
