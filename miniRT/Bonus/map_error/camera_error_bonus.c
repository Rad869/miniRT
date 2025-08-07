/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:05:38 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/05 13:49:47 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

int	check_coordinates(char *str)
{
	char	**values;
	int		valid;

	if (!str || count_comma_separated(str) != 3)
		return (0);
	values = ft_split(str, ',');
	if (!values)
		return (0);
	valid = (num_digitt(values[0]) && num_digitt(values[1])
			&& num_digitt(values[2]));
	ft_free_split(values);
	return (valid);
}

int	check_normalized_vector(char *str)
{
	double	x;
	double	y;
	double	z;

	if (!parse_vector_values(str, &x, &y, &z))
		return (0);
	if (x < -1 || x > 1 || y < -1 || y > 1 || z < -1 || z > 1)
		return (0);
	return (1);
}

int	check_camera_arg(char **line_splited)
{
	double	fov;

	if (ft_strcmp(line_splited[0], "C") != 0
		|| !check_coordinates(line_splited[1])
		|| !check_normalized_vector(line_splited[2])
		|| !num_digitt(line_splited[3]))
	{
		ft_free_split(line_splited);
		return (0);
	}
	fov = ft_atof(line_splited[3]);
	if (fov < 0 || fov > 180)
	{
		ft_free_split(line_splited);
		return (0);
	}
	return (1);
}

int	check_camera(char *line)
{
	char	**line_splited;
	char	*cleaned;

	cleaned = ft_strdup(line);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	if (count_arguments(cleaned) != 4)
	{
		printf("Error\nIn the camera mapping\n");
		free(cleaned);
		return (0);
	}
	line_splited = ft_split(cleaned, ' ');
	free(cleaned);
	if (!line_splited)
		return (0);
	if (check_camera_arg(line_splited) == 0)
	{
		printf("Error\nIn the camera mapping\n");
		return (0);
	}
	ft_free_split(line_splited);
	return (1);
}
