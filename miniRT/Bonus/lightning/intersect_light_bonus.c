/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_light_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 07:11:45 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/07 21:51:55 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

t_color	get_speculaire(t_colision *col, t_vector v, t_point inter, t_light *l)
{
	t_color		value;
	t_vector	h;
	t_vector	n;
	t_color		o_c;

	h = normalisation(add_vector(v,
				normalisation(substract_vect(l->origin, inter, inter)),
				inter));
	n = get_norm_surf(col->obj, col->type, inter);
	if (ft_strcmp(col->type, "sp") == 0)
		o_c = ((t_sphere *)col->obj)->color;
	else if (ft_strcmp(col->type, "cy") == 0)
		o_c = ((t_cylinder *)col->obj)->color;
	value.part1 = l->intensity * pow(dot_product(n, h), 512) * ((1 - 0.1)
			* o_c.part1 + 0.1);
	value.part2 = l->intensity * pow(dot_product(n, h), 512) * ((1 - 0.1)
			* o_c.part2 + 0.1);
	value.part3 = l->intensity * pow(dot_product(n, h), 512) * ((1 - 0.1)
			* o_c.part3 + 0.1);
	return (value);
}

static t_color	get_diff_color(t_color o_c, t_light *l,
									t_vector s_n, t_vector v)
{
	t_color	value;
	double	scalar;

	scalar = dot_product(s_n, v);
	value.part1 = 0;
	value.part2 = 0;
	value.part3 = 0;
	if (scalar < 0)
		return (value);
	value.part1 = l->intensity * l->color.part1 * scalar * o_c.part1;
	value.part2 = l->intensity * l->color.part2 * scalar * o_c.part2;
	value.part3 = l->intensity * l->color.part3 * scalar * o_c.part3;
	return (value);
}

t_color	pl_all_color_extend(double scalar1, double scalar2,
								t_light *l, t_color pl_col)
{
	t_color	value;

	value.part1 = 0;
	value.part2 = 0;
	value.part3 = 0;
	if (!((scalar1 < 0 && scalar2 < 0) || (scalar1 > 0 && scalar2 > 0)))
		return (value);
	if (scalar1 < 0)
		scalar1 *= -1;
	value.part1 = l->intensity * scalar1 * pl_col.part1 * l->color.part1;
	value.part2 = l->intensity * scalar1 * pl_col.part2 * l->color.part2;
	value.part3 = l->intensity * scalar1 * pl_col.part3 * l->color.part3;
	return (value);
}

t_color	pl_all_color(t_colision *c, t_point inter, t_vector v, t_light *l)
{
	t_vector	s_n;
	double		scalar1;
	double		scalar2;
	t_color		pl_col;

	if (ft_strcmp(c->type, "pl") == 0)
	{
		s_n = ((t_plan *)c->obj)->normal_vect;
		pl_col = ((t_plan *)c->obj)->color;
	}
	else
	{
		s_n = ((t_cylinder *)c->obj)->orientation;
		pl_col = ((t_cylinder *)c->obj)->color;
	}
	scalar1 = dot_product(v, s_n);
	scalar2 = dot_product(s_n, substract_vect(l->origin, inter, inter));
	return (pl_all_color_extend(scalar1, scalar2, l, pl_col));
}

t_color	get_all_col(t_colision *col, t_vector v,
		t_point inter, t_light *l)
{
	t_color		obj_col;
	t_vector	s_n;
	double		a;
	double		d;

	s_n = get_norm_surf(col->obj, col->type, inter);
	d = 1 / (1 + 0.00005 * distance(inter, l->origin)
			+ 0.000005 * pow(distance(inter, l->origin), 2));
	a = double_min(1, d);
	if (ft_strcmp(col->type, "sp") == 0)
		obj_col = ((t_sphere *)col->obj)->color;
	else if (ft_strcmp(col->type, "pl") == 0)
		return (pl_all_color(col, inter, v, l));
	else if (ft_strcmp(col->type, "cy") == 0 && !col->cap)
		obj_col = ((t_cylinder *)col->obj)->color;
	else if (ft_strcmp(col->type, "cy") == 0 && col->cap)
		return (pl_all_color(col, inter, v, l));
	obj_col = k_color(a, get_diff_color(obj_col,
				l, s_n, v));
	obj_col = add_color(obj_col, k_color(a, get_speculaire(col, v, inter, l)));
	return (obj_col);
}
