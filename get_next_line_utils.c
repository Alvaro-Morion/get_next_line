/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:09 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/21 13:32:50 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	if (s2)
	{
		while (s2[j])
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	str[i + j] = 0;
	return (str);
}

long long	ft_has_nl(char *s)
{
	long long	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\n' && s[i])
			i++;
		if (s[i] == '\n')
			return (i);
	}
	return (-1);
}

char	*ft_new_line(char **res)
{
	char		*line;
	char		*tres;
	long long	n;

	if (ft_has_nl(*res) != -1)
	{
		n = ft_has_nl(*res);
		tres = ft_strdup(*res);
		res[0][n + 1] = 0;
		line = ft_strdup(*res);
		free(*res);
		*res = ft_strdup(&(tres[n + 1]));
		free(tres);
		return (line);
	}
	free(*res);
	return (NULL);
}
