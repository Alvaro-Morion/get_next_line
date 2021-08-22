/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:50:31 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/22 10:51:38 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* Free line alocated memory and returns null (for errors)*/
char	*ft_free_null(char *line)
{
	free(line);
	return (NULL);
}

/* Modifies the buffer after reading a line, it moves whatever after nl to the 
 * beginin and adds \0 at the end of bufferl*/
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

/*1 If there is nl, it returns the line and modifiees the buffer. If there is 
 * not nl  * the programme enters this function because it is the last line, 
 * so it sets buffer  * to 0 and returns the line. In case of error returns 
 * null and frees line.*/

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

/* 1 Error check.
2 Copy buffer  from previous application on line till finding a new line or 
to the end.
2.1 If buffer has a nl it returns the line and changes the buffer. 
3 If the buffer has no nl, it reads the file (if possible) and it adds the 
new buffer to line. Repeats the process until buffer has an nl or the end 
of the file is reached.*/
char	*get_next_line(int fd)
{
	ssize_t		byte;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, buffer);
	if (!line)
		return (ft_free_null(line));
	if (ft_hasnl(buffer) != ft_strlen(buffer))
		return (ft_return(buffer, line));
	byte = BUFFER_SIZE;
	while (byte == BUFFER_SIZE && !ft_withnl(buffer))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
			return (ft_free_null(line));
		buffer[byte] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (ft_free_null(line));
		if (byte == BUFFER_SIZE)
			byte = ft_hasnl(buffer);
	}
	return (ft_return(buffer, line));
}
