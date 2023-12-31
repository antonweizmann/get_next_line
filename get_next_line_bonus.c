/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:08:09 by aweizman          #+#    #+#             */
/*   Updated: 2023/10/23 11:40:59 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	get_line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	return (i);
}

char	*new_line(char *line, int bytes_read)
{
	char	*new_line;
	char	*tmp;

	if (!line[bytes_read])
	{
		free (line);
		return (NULL);
	}
	new_line = ft_calloc((ft_strlen(line) - bytes_read + 1), sizeof(char));
	bytes_read++;
	tmp = new_line;
	while (line[bytes_read])
		*new_line++ = line[bytes_read++];
	free (line);
	return (tmp);
}

char	*get_result(char *line, int bytes_read)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!*line)
		return (NULL);
	tmp = ft_calloc(bytes_read + 2, sizeof(char));
	while (line[i] != '\n' && line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	if (line[i] == '\n' && line[i])
		tmp[i] = '\n';
	return (tmp);
}

char	*read_line(int *pos, int fd, char *line)
{
	char	*buffer;
	char	*tmp;

	if (!line)
		line = ft_calloc(1, sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (*pos > 0)
	{
		*pos = read(fd, buffer, BUFFER_SIZE);
		if (*pos == -1)
		{
			return (free(buffer), NULL);
		}
		buffer[*pos] = '\0';
		tmp = ft_strjoin(line, buffer);
		free (line);
		line = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*res;
	int			bytes_read;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	pos = 1;
	line[fd] = read_line(&pos, fd, line[fd]);
	if (!line[fd])
		return (NULL);
	bytes_read = get_line_len(line[fd]);
	res = get_result(line[fd], bytes_read);
	line[fd] = new_line(line[fd], bytes_read);
	return (res);
}
