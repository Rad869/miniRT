/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 06:57:13 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/05 13:49:47 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

double	plan_equation(t_vector dir, t_plan pl)
{
	double	dist;

	dist = 0;
	if (dot_product(pl.normal_vect, dir) != 0)
	{
		dist = ((pl.origin.x_p - dir.origin_d.x_p) * pl.normal_vect.x_d
				+ (pl.origin.y_p - dir.origin_d.y_p) * pl.normal_vect.y_d
				+ (pl.origin.z_p - dir.origin_d.z_p) * pl.normal_vect.z_d)
			/ dot_product(dir, pl.normal_vect);
		if (dist > 0)
			return (dist);
	}
	return (-1);
}

static void	update_colision_plane(t_colision *col, double t, t_plan *pl)
{
	double	t1;

	t1 = col->dist;
	if (t < t1 && t > 0)
	{
		col->obj = (void *) pl;
		col->dist = t;
		col->type[0] = 'p';
		col->type[1] = 'l';
		col->type[2] = '\0';
	}
}

void	transform_normal_vect_a(t_vector *n, double a)
{
	double	theta;
	double	phi;

	*n = normalisation(*n);
	theta = atan2(sqrt(pow(n->x_d, 2) + pow(n->y_d, 2)), n->z_d);
	phi = atan2(n->y_d, n->x_d);
	n->x_d = sin(a) * sin(phi) + cos(a) * sin(theta) * cos(phi);
	n->y_d = cos(a) * sin(theta) * sin(phi) - sin(a) * cos(phi);
	n->z_d = cos(a) * cos(theta);
}

void	transform_normal_vect_b(t_vector *n, double b)
{
	double	theta;
	double	phi;

	*n = normalisation(*n);
	theta = atan2(sqrt(pow(n->x_d, 2) + pow(n->y_d, 2)), n->z_d);
	phi = atan2(n->y_d, n->x_d);
	n->x_d = cos(b) * sin(theta) * cos(phi) + sin(b) * cos(phi) * cos(theta);
	n->y_d = sin(b) * sin(phi) * cos(theta) + cos(b) * sin(theta) * sin(phi);
	n->z_d = cos(b) * cos(theta) - sin(b) * sin(theta);
}

void	plan_int(t_vector dir, t_plane_list **plan, t_colision *col)
{
	t_plan			*pl;
	t_plane_list	*pl_l;

	dir = normalisation(dir);
	pl_l = *plan;
	while (pl_l != NULL)
	{
		pl = pl_l->plane;
		pl->normal_vect = normalisation(pl->normal_vect);
		update_colision_plane(col, plan_equation(dir, *pl), pl);
		pl_l = pl_l->next;
	}
}
