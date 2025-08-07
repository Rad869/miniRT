/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection_suite_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:38:09 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/08 03:09:16 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

void	init_cylinder_variables(t_cylinder *cyl, t_slove_c *slove)
{
	slove->r1 = substract_vect(cyl->origin, to_point(k_vector(cyl->height / 2,
					cyl->orientation)), cyl->origin);
	slove->r2 = add_vector(to_vector(cyl->origin, cyl->origin),
			k_vector(cyl->height / 2, cyl->orientation),
			cyl->origin);
	slove->s = normalisation(substract_vect(to_point(slove->r2),
				to_point(slove->r1), cyl->origin));
}

void	calculate_intersection_vectors(t_vector vec, t_slove_c *slove)
{
	slove->rao = cross_product(slove->s,
			cross_product(substract_vect(vec.origin_d,
					to_point(slove->r1), vec.origin_d), slove->s));
	slove->va = cross_product(slove->s, cross_product(vec, slove->s));
}

int	is_on_lateral_surface(t_point ray, t_slove_c slove)
{
	return (dot_product(slove.s, substract_vect(ray,
				to_point(slove.r1), ray)) > 0
		&& dot_product(slove.s, substract_vect(ray,
				to_point(slove.r2), ray)) < 0);
}

void	solve_cylinder(t_vector vec, t_cylinder *cyl, t_colision *col)
{
	t_slove_c	slove;
	t_point		ray;
	t_param		param;

	init_cylinder_variables(cyl, &slove);
	calculate_intersection_vectors(vec, &slove);
	slove.t = put_lateral(slove.va, slove.rao, cyl);
	ray.x_p = vec.origin_d.x_p + vec.x_d * slove.t;
	ray.y_p = vec.origin_d.y_p + vec.y_d * slove.t;
	ray.z_p = vec.origin_d.z_p + vec.z_d * slove.t;
	if (is_on_lateral_surface(ray, slove))
		update_colision_cylinder(col, slove.t, cyl, 0);
	param.vec = vec;
	param.s = slove.s;
	param.rr1 = to_point(slove.r1);
	param.rr2 = to_point(slove.r2);
	put_disc(param, col, cyl);
}

void	cyl_int(t_vector dir, t_cylinder_list **cyl_l, t_colision *col)
{
	t_cylinder		*cyl;
	t_cylinder_list	*cyl_tmp_l;

	cyl_tmp_l = *cyl_l;
	while (cyl_tmp_l != NULL)
	{
		cyl = cyl_tmp_l->cylinder;
		solve_cylinder(dir, cyl, col);
		cyl_tmp_l = cyl_tmp_l->next;
	}
}
