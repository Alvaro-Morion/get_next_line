/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:17:18 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/22 10:17:25 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* protegida de cadenas nulas y overflow */
size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_src;
	char	*ptr_dest;

	i = 0;
	ptr_src = (void *)src;
	ptr_dest = dest;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}

// Modificada para que solo una la cadena 2 hasta encontrar un salto de línea */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_hasnl(s2) + 1 + 1));
	if (!str)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	ft_memcpy(str, s1, i);
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
		if (s2[j - 1] == '\n')
			break ;
	}
	str[i + j] = '\0';
	free((char *)s1);
	return (str);
}

/*Devuelve 	1 si hay salto y 0 si no*/
int	ft_withnl(char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

/* Devielve la posición del primer salto de línea o la longitud de str si 
no hay ninguno*/
size_t	ft_hasnl(char const *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != '\n' && str[i])
			i++;
	return (i);
}
