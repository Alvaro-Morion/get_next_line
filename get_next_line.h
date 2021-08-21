/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:27:29 by amorion-          #+#    #+#             */
/*   Updated: 2021/08/21 13:26:31 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

size_t	ft_strlen(char const *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_withnl(char *str);
size_t	ft_hasnl(char const *str);
char	*ft_free_null(char *line);
void	ft_mod_buff(char str[], size_t n);
char	*ft_return(char buffer[], char *line);
char	*get_next_line(int fd);

#endif
