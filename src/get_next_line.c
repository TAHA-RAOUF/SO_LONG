/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moraouf <moraouf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 21:09:42 by taha_laylay       #+#    #+#             */
/*   Updated: 2025/03/27 14:34:48 by moraouf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char **reste, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(*reste, buffer);
	free(*reste);
	reste = NULL;
	return (tmp);
}

static char	*get_line(char **reste)
{
	size_t	len;
	char	*line;
	char	*tmp;

	len = 0;
	if (!*reste || **reste == '\0')
	{
		return (NULL);
	}
	while ((*reste)[len] != '\n' && (*reste)[len] != '\0')
		len++;
	if ((*reste)[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *reste, len);
	line[len] = '\0';
	tmp = ft_strdup((*reste) + len);
	free(*reste);
	*reste = tmp;
	return (line);
}

char	*read_file(char *reste, char *buffer, int fd)
{
	ssize_t	bytes;

	while (!ft_strchr(reste, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		reste = ft_strjoin_free(&reste, buffer);
	}
	free(buffer);
	if (!reste || reste[0] == '\0')
	{
		free(reste);
		return (NULL);
	}
	return (reste);
}

char	*get_next_line(int fd)
{
	static char	*reste;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reste = read_file(reste, buffer, fd);
	return (get_line(&reste));
}
