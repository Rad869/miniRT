/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_intersection_suite.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:27:57 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/07 21:57:12 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static void	update_colisions(t_colision *col, double t, void *obj, char *type)
{
	double	t1;

	t1 = col->dist;
	if (t < t1 && t > 0)
	{
		col->obj = obj;
		col->dist = t + 0.0001;
		col->type[0] = type[0];
		col->type[1] = type[1];
		col->type[2] = '\0';
	}
}

void	plan_int_l(t_vector dir, t_plane_list **plan, t_colision *col)
{
	t_plan			*pl;
	t_plane_list	*pl_l;

	dir = normalisation(dir);
	pl_l = *plan;
	while (pl_l != NULL)
	{
		pl = pl_l->plane;
		pl->normal_vect = normalisation(pl->normal_vect);
		update_colisions(col, plan_equation(dir, *pl), (void *)pl, "pl");
		pl_l = pl_l->next;
	}
}

void	sphere_int_l(t_vector dir, t_sphere_list **sp_l, t_colision *col)
{
	double			a;
	double			b;
	double			c;
	t_sphere		*sp;
	t_sphere_list	*sp_temp_l;

	dir = normalisation(dir);
	sp_temp_l = *sp_l;
	while (sp_temp_l != NULL)
	{
		sp = sp_temp_l->sphere;
		a = pow(dir.x_d, 2) + pow(dir.y_d, 2) + pow(dir.z_d, 2);
		b = 2 * ((dir.origin_d.x_p - sp->origin.x_p) * dir.x_d \
				+ (dir.origin_d.y_p - sp->origin.y_p) * dir.y_d \
				+ (dir.origin_d.z_p - sp->origin.z_p) * dir.z_d);
		c = pow(dir.origin_d.x_p - sp->origin.x_p, 2) \
				+ pow(dir.origin_d.y_p - sp->origin.y_p, 2) \
				+ pow(dir.origin_d.z_p - sp->origin.z_p, 2) \
				- pow(sp->radius, 2);
		update_colisions(col, quadratique_equation(a, b, c), (void *) sp, "sp");
		sp_temp_l = sp_temp_l->next;
	}
}
