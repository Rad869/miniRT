/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:38:45 by fifrandr          #+#    #+#             */
/*   Updated: 2025/01/27 12:11:57 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

int		ft_strlen_get(char *str);
char	*ft_strchr_get(char *str, int c);
char	*ft_strjoin_get(char *s1, char *s2);
char	*ft_strtrim_get(char *s1);
char	*ft_reste(char *s2);
char	*read_line(int fd, char *txt);
char	*get_next_line(int fd);
#endif
