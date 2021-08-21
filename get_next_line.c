/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:50:31 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/21 17:57:55 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* libera la memoria de la línea y devuelve nulo para los casos de error.*/
char	*ft_free_null(char *line)
{
	free(line);
	return (NULL);
}

/* Para modificar el buffer después de leer una línea, mueve lo que hay después
del /n al principio y rellena con \0 hasta el final*/
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

/*1 Si hay un salto de línea en buffer, retorna la línea y modifica el buffer 
con ft_cut si hay más carácteres.
2 Si el salto de línea está al final del buffer 
3 Con error retorna nulo */

char	*ft_return(char buffer[], char *line)
{
	size_t	i;

	i = 0;
	if (ft_hasnl(buffer) != ft_strlen(buffer))
	{
		ft_mod_buff(buffer, ft_hasnl(buffer) + 1);
		if (ft_withnl(line) || ft_strlen(line))
			return (line);
	}
	else if (ft_hasnl(buffer) == ft_strlen(buffer))
	{
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

/* 1 Comrueba errores
2 Copia el buffer preexistente en la línea y si hay salto de línea devielve 
la línea y cambia el buffer.
3 Si no hay salto en el buffer, lee el fichero (si puede) y añade el nuevo
buffer a line, verifica si hay salto de línea y si lo hay rompe el bucle.
Devuelve ala línea una vez se ha roto el bucle, bien por salto de línea o 
bien porque se acaba el fichero.*/
char	*get_next_line(int fd)
{
	int			byte;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
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
/*#include<stdio.h>
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
