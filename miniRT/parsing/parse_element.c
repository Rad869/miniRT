/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:43:47 by fifrandr          #+#    #+#             */
/*   Updated: 2025/02/21 08:25:09 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	parse_color(char *str, t_color *color)
{
	char	**parts;
	double	values[3];

	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	values[0] = ft_atof(parts[0]) / 255.0;
	values[1] = ft_atof(parts[1]) / 255.0;
	values[2] = ft_atof(parts[2]) / 255.0;
	color->part1 = values[0];
	color->part2 = values[1];
	color->part3 = values[2];
	ft_free_split(parts);
	return (1);
}

int	parse_point(char *str, t_point *point)
{
	char	**parts;

	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	point->x_p = ft_atof(parts[0]);
	point->y_p = ft_atof(parts[1]);
	point->z_p = ft_atof(parts[2]);
	ft_free_split(parts);
	return (1);
}

int	parse_vector(char *str, t_vector *vector)
{
	char	**parts;
	double	values[3];

	parts = ft_split(str, ',');
	if (!parts)
		return (0);
	values[0] = ft_atof(parts[0]);
	values[1] = ft_atof(parts[1]);
	values[2] = ft_atof(parts[2]);
	vector->x_d = values[0];
	vector->y_d = values[1];
	vector->z_d = values[2];
	ft_free_split(parts);
	return (1);
}

int	parse_camera(char *line, t_camera *camera)
{
	char	**parts;

	parts = ft_split(line, ' ');
	if (!parts)
		return (0);
	parse_point(parts[1], &camera->origin);
	parse_vector(parts[2], &camera->orientation);
	camera->orientation.origin_d = camera->origin;
	camera->field_of_view = ft_atof(parts[3]);
	if (camera->field_of_view == 180.0)
		camera->field_of_view = 179.9;
	ft_free_split(parts);
	return (1);
}
