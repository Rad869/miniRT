/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersection_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 14:38:29 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/07 21:40:18 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

void	update_colision_cylinder(t_colision *col, double t,
									t_cylinder *cyl, int cap)
{
	double	t1;

	t1 = col->dist;
	if (t > 0 && t < t1)
	{
		col->obj = (void *)cyl;
		col->dist = t;
		col->type[0] = 'c';
		col->type[1] = 'y';
		col->type[2] = '\0';
		col->cap = cap;
	}
}

double	put_lateral(t_vector Va, t_vector Rao, t_cylinder *cyl)
{
	double	a;
	double	b;
	double	c;

	a = dot_product(Va, Va);
	b = 2 * dot_product(Rao, Va);
	c = dot_product(Rao, Rao) - pow(cyl->diameter / 2, 2);
	return (quadratique_equation(a, b, c));
}

void	put_disc1(t_param data, t_colision *col, t_cylinder *cyl)
{
	double	t;
	t_point	p;

	t = 0;
	if (dot_product(to_vector(data.rr1, data.rr1), data.vec) != 0)
	{
		t = ((data.rr1.x_p - data.vec.origin_d.x_p) * data.s.x_d + (data.rr1.y_p
					- data.vec.origin_d.y_p) * data.s.y_d + (data.rr1.z_p
					- data.vec.origin_d.z_p) * data.s.z_d)
			/ dot_product(data.s, data.vec);
		p.x_p = data.vec.origin_d.x_p + t * data.vec.x_d;
		p.y_p = data.vec.origin_d.y_p + t * data.vec.y_d;
		p.z_p = data.vec.origin_d.z_p + t * data.vec.z_d;
		if (t > 0 && distance(p, data.rr1) <= cyl->diameter / 2)
			update_colision_cylinder(col, t, cyl, 1);
	}
}

void	put_disc2(t_param data, t_colision *col, t_cylinder *cyl)
{
	double	t;
	t_point	p;

	t = 0;
	if (dot_product(to_vector(data.rr2, data.rr2), data.vec) != 0)
	{
		t = ((data.rr2.x_p - data.vec.origin_d.x_p) * data.s.x_d
				+ (data.rr2.y_p - data.vec.origin_d.y_p)
				* data.s.y_d + (data.rr2.z_p
					- data.vec.origin_d.z_p) * data.s.z_d)
			/ dot_product(data.s, data.vec);
		p.x_p = data.vec.origin_d.x_p + t * data.vec.x_d;
		p.y_p = data.vec.origin_d.y_p + t * data.vec.y_d;
		p.z_p = data.vec.origin_d.z_p + t * data.vec.z_d;
		if (t > 0 && distance(p, data.rr2) <= cyl->diameter / 2)
			update_colision_cylinder(col, t, cyl, 1);
	}
}

void	put_disc(t_param data, t_colision *col, t_cylinder *cyl)
{
	put_disc1(data, col, cyl);
	put_disc2(data, col, cyl);
}
