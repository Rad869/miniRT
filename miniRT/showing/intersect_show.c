/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:11:03 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/17 07:52:00 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

// void	transform_vector(t_vector *vec, t_scene *scene)
// {
// 	return ;
// }

void	intersect_show(t_scene *scene)
{
	t_vector	vec;
	t_scr_p		point;
	t_colision	col;

	point.y = 0;
	vec.origin_d = scene->camera.origin;
	vec.z_d = scene->screen_cam_dist;
	while(point.y < scene->win->heigth)
	{
		vec.y_d = - (scene->dist_px_real * scene->win->heigth) / 2
			+ point.y * scene->dist_px_real;
		point.x = 0;
		while(point.x < scene->win->width)
		{
			vec.x_d = - (scene->dist_px_real * scene->win->width) / 2
			+ point.x * scene->dist_px_real;
			intersection(scene, &col, transform_cam(scene, vec), point);
			point.x++;
		}
		point.y++;
	}
}
