/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:36:44 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/05 13:50:29 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*append_str(char *original, char *append)
{
	if (!original)
	{
		original = malloc(sizeof(char) * 1);
		original[0] = '\0';
	}
	original = ft_strjoin_get(original, append);
	return (original);
}

char	*read_line(int fd, char *txt)
{
	char	*strt;
	int		read_result;

	strt = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!strt)
		return (NULL);
	read_result = 1;
	while (read_result != 0 && !ft_strchr_get(txt, '\n'))
	{
		read_result = read(fd, strt, BUFFER_SIZE);
		if (read_result == -1)
		{
			free(strt);
			free(txt);
			return (NULL);
		}
		strt[read_result] = '\0';
		txt = append_str(txt, strt);
	}
	free(strt);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*txt;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	txt = read_line(fd, txt);
	if (!txt)
		return (NULL);
	line = ft_strtrim_get(txt);
	txt = ft_reste(txt);
	return (line);
}
