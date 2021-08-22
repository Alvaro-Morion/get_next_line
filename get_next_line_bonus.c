/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:16:06 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/22 10:51:16 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_null(char *line)
{
	free(line);
	return (NULL);
}

void	ft_mod_buff(char str[], size_t n)
{
	size_t	i;

	i = 0;
	while (n < BUFFER_SIZE)
	{
		str[i] = str[n];
		n++;
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		str[i] = 0;
		i++;
	}
}

char	*ft_return(char buffer[], char *line)
{
	size_t	i;

	if (ft_hasnl(buffer) != ft_strlen(buffer))
	{
		ft_mod_buff(buffer, ft_hasnl(buffer) + 1);
		if (ft_withnl(line) || ft_strlen(line))
			return (line);
	}
	else if (ft_hasnl(buffer) == ft_strlen(buffer))
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			buffer[i] = 0;
			i++;
		}
		if (ft_withnl(line) || ft_strlen(line))
			return (line);
	}
	return (ft_free_null(line));
}

char	*get_next_line(int fd)
{
	ssize_t		byte;
	char		*line;
	static char	buffer[1024][BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, buffer[fd]);
	if (!line)
		return (ft_free_null(line));
	if (ft_hasnl(buffer[fd]) != ft_strlen(buffer[fd]))
		return (ft_return(buffer[fd], line));
	byte = BUFFER_SIZE;
	while (byte == BUFFER_SIZE && !ft_withnl(buffer[fd]))
	{
		byte = read(fd, buffer[fd], BUFFER_SIZE);
		if (byte < 0)
			return (ft_free_null(line));
		buffer[fd][byte] = '\0';
		line = ft_strjoin(line, buffer[fd]);
		if (!line)
			return (ft_free_null(line));
		if (byte == BUFFER_SIZE)
			byte = ft_hasnl(buffer[fd]);
	}
	return (ft_return(buffer[fd], line));
}
