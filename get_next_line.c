/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:50:31 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/20 17:35:02 by amorion-         ###   ########.fr       */
/*                        L                                                    */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<string.h>
int	hasnl(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

char	*ft_fill_line(char	**res)
{
	int		n;
	char	*line;
	char	*temp;

	if(!*res) // Ha habido un error o no hay líneas
		return (NULL);
	n = hasnl(*res);
	printf("%d\n", n);
	if (n == -1)	// Si entras aquí es la última línea del fichero
	{
		line = ft_strdup(*res);
		free(*res);
	}
	else //Una línea cualquiera
	{
		line = ft_substr(*res, 0, n + 1);
		temp = ft_strdup(*res + n + 1);
		free(*res);
		*res = temp;
		free(temp);
	}
	printf("Line: %s\n", line);
	return(line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*temp;
	char		*line;
	static char *res = NULL;
	size_t		byte;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (BUFFER_SIZE < 1 || fd < 1 || !buffer) //comprobar errores
		return (NULL);
	if (!res || hasnl(res) == -1) // Comprobar si hay resto de última applicación y si lo hay que no tiene saltos de línea
	{
		byte = read(fd, buffer, BUFFER_SIZE);	// leer el fichero
		while(byte > 0) //Mientras no haya problemas ...
		{
			printf("Buffer: %s\n", buffer);
			if (!res) // si no hay resto duplicar buffer en él.
				res = ft_strdup(buffer);
			else // si lo hay añadir buffer al resto
			{
				temp = ft_strjoin(res, buffer);
				free(res);
				res = temp;
			}
			if(hasnl(res) != -1) // Comprobar salto de línea y dejar de leer si lo hay.
				break;
			read(fd, buffer, BUFFER_SIZE);
		}
	}
	free(buffer); //ya no se necesita buffer más
	printf("res antes: %s\n", res);
	line = ft_fill_line(&res);
	printf("res despues: %s\n", res);
	return(line);
}
#include<fcntl.h>

int main()
{
	int fd;
	char *line;

	fd = open("./file", O_RDONLY);
	line = get_next_line(fd);
	//printf("%s\n", line);
	/*while(line)
	{
		printf("%s\n", get_next_line(fd));
	}*/
	close(fd);
	return (0);
}
