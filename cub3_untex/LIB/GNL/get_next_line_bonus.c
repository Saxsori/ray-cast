/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljaber <aaljaber@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:47:21 by aaljaber          #+#    #+#             */
/*   Updated: 2022/07/14 06:14:29 by aaljaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*lineout(char *readtxt)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	if (!readtxt[i])
		return (NULL);
	while (readtxt[i] != '\0' && readtxt[i] != '\n')
		i++;
	string = (char *)malloc(sizeof(char) * (i + 2));
	if (!string)
		return (NULL);
	i = 0;
	j = 0;
	while (readtxt[i] != '\0' && readtxt[i] != '\n')
	{
		string[j++] = readtxt[i++];
	}
	if (readtxt[i] == '\n')
	{
		string[j++] = readtxt[i++];
	}
	string[j] = '\0';
	return (string);
}

static char	*nw_readtxt(char *readtxt)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	while (readtxt[i] != '\0' && readtxt[i] != '\n')
		i++;
	if (!readtxt[i])
	{
		free (readtxt);
		return (NULL);
	}
	string = (char *)malloc(sizeof(char) * (ft_strlen(readtxt) - i + 1));
	if (!string)
		return (NULL);
	i += 1;
	j = 0;
	while (readtxt[i] != '\0')
		string[j++] = readtxt[i++];
	string[j] = '\0';
	free (readtxt);
	return (string);
}

static char	*reading(int fd, char *readtxt)
{
	int		bytes;
	char	*buffer;

	buffer = malloc((sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buffer)
		return (NULL);
	bytes = 42;
	while (!gnl_strchr(readtxt, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		if (!readtxt)
		{
			readtxt = (char *)malloc(sizeof(char));
			readtxt[0] = '\0';
		}
		readtxt = ft_strjoin(readtxt, buffer);
	}
	free (buffer);
	return (readtxt);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*readtxt[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readtxt[fd] = reading(fd, readtxt[fd]);
	if (!readtxt[fd])
		return (NULL);
	line = lineout(readtxt[fd]);
	readtxt[fd] = nw_readtxt(readtxt[fd]);
	return (line);
}
