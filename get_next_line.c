/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:50:31 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/19 12:20:17 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
char	*ft_free(char *line)
{
	free(line);
	return (NULL);
}

size_t	line_len(char *str)
{
	size_t	len;

	len = 0;
	while(str[len] && str[len] != '\n')
	{
	//printf("%zu %c\n", len, str[len]);
		len++;
	}
	//printf("Last %zu %c",len, str[len]); 
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	static size_t count = 0;

	//printf("%zu\n", count);
	if (BUFFER_SIZE < 1 || fd < 1)
	{
		//write(1, "0", 1);
		return (NULL);
	}
	/*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		write(1, "1", 1);
		return (ft_free(buffer));
	}*/
	if (read(fd, &buffer[count], BUFFER_SIZE) < 0)
	{
		//write(1, "2", 1);
		return (NULL);
	}
	//printf("%s\n", &buffer[count]);
	line = ft_strdup(&buffer[count], line_len(&buffer[count]));
	if (!line || !line_len(&buffer[count]))
		return(ft_free(line));
	count += line_len(&buffer[count]);
	return(line);
}
#include<fcntl.h>

int main()
{
	int fd;
	char *line;
	int i;
	i = 1;
	fd = open("./file", O_RDONLY);
	line = "a";
	while(line)
	{
		line = get_next_line(fd);
		printf("%d : %s", i, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (0);
}
