/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:06:22 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/02 12:34:10 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

char	*trim_end(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && ft_isspace(str[len - 1]))
	{
		str[--len] = '\0';
	}
	return (str);
}

int	count_arguments(char *str)
{
	int		count;
	int		in_argument;
	int		i;
	char	*trimmed;

	trimmed = ft_strdup(str);
	trim_end(trimmed);
	i = 0;
	count = 0;
	in_argument = 0;
	while (trimmed[i] != '\0')
	{
		if (ft_isspace(trimmed[i]))
			in_argument = 0;
		else if (!in_argument)
		{
			in_argument = 1;
			count++;
		}
		i++;
	}
	free(trimmed);
	return (count);
}

int	check_light_arg(char **line_splited)
{
	double	brightness;

	if (ft_strcmp(line_splited[0], "L") != 0
		|| !check_coordinates(line_splited[1]) || !num_digitt(line_splited[2])
		|| !check_color(line_splited[3]))
	{
		ft_free_split(line_splited);
		return (0);
	}
	brightness = ft_atof(line_splited[2]);
	if (brightness < 0 || brightness > 1)
	{
		ft_free_split(line_splited);
		return (0);
	}
	return (1);
}

int	check_light(char *line)
{
	char	**line_splited;
	char	*cleaned;

	cleaned = ft_strdup(line);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	if (count_arguments(cleaned) != 4)
	{
		printf("Error\nIn the light mapping\n");
		free(cleaned);
		return (0);
	}
	line_splited = ft_split(cleaned, ' ');
	free(cleaned);
	if (!line_splited)
		return (0);
	if (check_light_arg(line_splited) == 0)
	{
		printf("Error\nIn the light mapping\n");
		return (0);
	}
	ft_free_split(line_splited);
	return (1);
}
