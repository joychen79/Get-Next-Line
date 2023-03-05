/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingchen <jingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:20:41 by jingchen          #+#    #+#             */
/*   Updated: 2023/03/05 13:07:25 by jingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

size_t		ft_strlen(char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char	*s2);
char		*get_next_line(int fd);
void		*ft_calloc(int count, int size);
char		*join_buffer(char *old, char *new);

#endif
