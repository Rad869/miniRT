/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:38:29 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/18 11:05:09 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	update_colision_cylinder(t_colision *col, double t, t_cylinder *cyl)
{
	double	t1;

	t1 = col->dist;
	if (t > 0 && t < t1)
	{
		col->obj = (void *) cyl;
		col->dist = t;
		col->type[0] = 'c';
		col->type[1] = 'y';
		col->type[2] = '\0';
	}
}

void	solve_cylinder(t_vector dir, t_cylinder *cyl, t_colision *col)
{
	double		a;
	double		b;
	double		c;
	t_vector	R;
	t_vector	V;

	cyl->orientation = normalisation(cyl->orientation);
	dir = normalisation(dir);
	R = cross_product(cyl->orientation, cross_product(substract_vect(dir.origin_d, cyl->origin, dir.origin_d), cyl->orientation));
	V = cross_product(cross_product(cyl->orientation, dir), cyl->orientation);
	a = dot_product(V, V);
	b = 2 * dot_product(R, V);
	c = dot_product(R, R) - pow(cyl->diameter / 2.0, 2);
	update_colision_cylinder(col, quadratique_equation(a, b , c), cyl);
}

void	cyl_int(t_vector dir, t_cylinder_list **cyl_list, t_colision *col)
{
	t_cylinder		*cyl;
	t_cylinder_list	*cyl_temp_l;

	cyl_temp_l = *cyl_list;
	while (cyl_temp_l != NULL)
	{
		cyl = cyl_temp_l->cylinder;
		solve_cylinder(dir, cyl, col);
		cyl_temp_l = cyl_temp_l->next;
	}
}
