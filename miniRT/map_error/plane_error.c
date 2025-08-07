/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:08:50 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/02 12:34:38 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	count_comma(char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma_count++;
		i++;
	}
	return (comma_count);
}

int	count_comma_separated(char *str)
{
	int	count;
	int	in_token;
	int	i;

	i = 0;
	count = 0;
	in_token = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			in_token = 0;
		else if (!in_token)
		{
			in_token = 1;
			count++;
		}
		i++;
	}
	if (count_comma(str) != 2)
		return (0);
	return (count);
}

int	check_plane_arg(char **line_splited)
{
	if (ft_strcmp(line_splited[0], "pl") != 0
		|| !check_coordinates(line_splited[1])
		|| !check_normalized_vector(line_splited[2])
		|| !check_color(line_splited[3]))
	{
		ft_free_split(line_splited);
		return (0);
	}
	return (1);
}

int	check_plane(char *line)
{
	char	**line_splited;
	char	*cleaned;

	cleaned = ft_strdup(line);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	if (count_arguments(cleaned) != 4)
	{
		printf("Error\nIn the plan mapping\n");
		free(cleaned);
		return (0);
	}
	line_splited = ft_split(cleaned, ' ');
	free(cleaned);
	if (!line_splited)
		return (0);
	if (check_plane_arg(line_splited) == 0)
	{
		printf("Error\nIn the plan mapping\n");
		return (0);
	}
	ft_free_split(line_splited);
	return (1);
}
