/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_elements_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:12:50 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/08 02:49:19 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

void	init_map_elements(t_map_elements *elements)
{
	elements->ambient_count = 0;
	elements->camera_count = 0;
	elements->ligth_count = 0;
	elements->sphere_count = 0;
	elements->plane_count = 0;
	elements->cylinder_count = 0;
}

int	check_map_elements(t_map_elements *elements)
{
	if (elements->ambient_count != 1 || elements->camera_count != 1
		|| elements->ligth_count == 0)
		return (0);
	if (elements->sphere_count == 0 && elements->plane_count == 0
		&& elements->cylinder_count == 0 && elements->ligth_count == 0)
		return (0);
	return (1);
}

int	update_map_elements(char *line, t_map_elements *elements)
{
	if (ft_strchr(line, 'A') && ambient_ligth(line))
		elements->ambient_count++;
	else if (ft_strchr(line, 'C') && check_camera(line))
		elements->camera_count++;
	else if (ft_strchr(line, 'm') && ft_strchr(line, 'l') && check_light(line))
		elements->ligth_count++;
	else if (ft_strchr(line, 's') && check_sphere(line))
		elements->sphere_count++;
	else if (ft_strchr(line, 'p') && ft_strchr(line, 'l') && check_plane(line))
		elements->plane_count++;
	else if (ft_strchr(line, 'c') && check_cylinder(line))
		elements->cylinder_count++;
	else
		return (0);
	return (1);
}
