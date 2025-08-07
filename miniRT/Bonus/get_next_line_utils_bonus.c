/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:58:00 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/05 13:50:19 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_get(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_get(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (0);
}

char	*ft_strjoin_get(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen_get(s1)
			+ ft_strlen_get(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strtrim_get(char *s1)
{
	int		i;
	char	*str;

	i = 0;
	if (!s1[i])
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_reste(char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s2[i] != '\0' && s2[i] != '\n')
		i++;
	if (!s2[i])
	{
		free(s2);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ft_strlen_get(s2) - i + 1);
	if (!str)
		return (NULL);
	i++;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	free (s2);
	return (str);
}
