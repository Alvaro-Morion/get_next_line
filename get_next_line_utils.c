/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:09 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/20 16:42:20 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t 	i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while(s[i])
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
		return 0;
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
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

char	*ft_substr(char *str, size_t start, size_t len)
{
	size_t	i;
	char	*substr;

	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		free(substr);
		return (NULL);
	}
	i = 0;
	while(str[start + i] && i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	return(substr);			
}
