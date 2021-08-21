/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:50:31 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/21 13:32:55 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*tres;
	char		*line;
	size_t		byte;
	static char	*res;

	byte = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if (BUFFER_SIZE < 1 || fd < 1 || fd > 1024 || !buffer || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!res || ft_has_nl(res) == -1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		while (byte > 0)
		{
			buffer[BUFFER_SIZE] = 0;
			if (!res)
				res = ft_strdup(buffer);
			else
			{
				tres = ft_strjoin(res, buffer);
				free(res);
				res = tres;
			}
			if (ft_has_nl(res) != -1)
				break ;
			byte = read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer);
	line = ft_new_line(&res);
	return (line);
}
/*
#include<fcntl.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	while(line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
