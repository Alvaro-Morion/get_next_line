/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:09 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/22 12:56:24 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* protected from null string and overflow */
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

/* Modified to join s2 until a nl is found */
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
	return (NULL); //Mod
}

/* 1 if nl 0 otherwise */
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

/*It returns the position of the first nl or the length of the string*/
size_t	ft_hasnl(char const *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i] != '\n' && str[i])
			i++;
	return (i);
}
