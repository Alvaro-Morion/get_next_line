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
# include<stdlib.h>
# include<unistd.h>
char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
long long	ft_has_nl(char *s);
char		*ft_new_line(char **res);
#endif
