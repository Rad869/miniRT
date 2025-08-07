/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_show.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:11:03 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/28 09:46:44 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static void	transform_vect(t_scene *scene)
{
	t_cylinder_list	*cyl_l;
	t_plane_list	*pl_l;

	cyl_l = scene->cylinder;
	pl_l = scene->plan;
	while (cyl_l)
	{
		transform_normal_vect_a(&cyl_l->cylinder->orientation,
			cyl_l->cylinder->a);
		transform_normal_vect_b(&cyl_l->cylinder->orientation,
			cyl_l->cylinder->b);
		cyl_l->cylinder->a = 0;
		cyl_l->cylinder->b = 0;
		cyl_l = cyl_l->next;
	}
	while (pl_l)
	{
		transform_normal_vect_a(&pl_l->plane->normal_vect,
			pl_l->plane->a);
		transform_normal_vect_b(&pl_l->plane->normal_vect,
			pl_l->plane->b);
		pl_l->plane->a = 0;
		pl_l->plane->b = 0;
		pl_l = pl_l->next;
	}
}

void	intersect_show(t_scene *scene)
{
	t_vector	vec;
	t_scr_p		point;
	t_colision	col;

	point.y = 0;
	vec.origin_d = scene->camera.origin;
	vec.z_d = scene->screen_cam_dist;
	transform_vect(scene);
	while (point.y < scene->win->heigth)
	{
		vec.y_d = -(scene->dist_px_real * scene->win->heigth) / 2 + point.y
			* scene->dist_px_real;
		point.x = 0;
		while (point.x < scene->win->width)
		{
			vec.x_d = -(scene->dist_px_real * scene->win->width) / 2 + point.x
				* scene->dist_px_real;
			intersection(scene, &col, transform_cam(scene, vec,
					scene->camera.rho), point);
			point.x++;
		}
		point.y++;
	}
	mlx_put_image_to_window(scene->win->mlx, scene->win->win, scene->win->img,
		0, 0);
}
