/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:01:28 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/17 11:26:25 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static void	update_colision_sphere(t_colision *col, double t, t_sphere *sp)
{
	double	t1;

	t1 = col->dist;
	if (t < t1 && t > 0)
	{
		col->obj = (void *) sp;
		col->dist = t;
		col->type[0] = 's';
		col->type[1] = 'p';
		col->type[2] = '\0';
	}
}

void	sphere_int(t_vector dir, t_sphere_list **sp_l, t_colision *col)
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
		update_colision_sphere(col, quadratique_equation(a, b, c), sp);
		sp_temp_l = sp_temp_l->next;
	}
}
