/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 07:11:45 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/07 22:20:49 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_color	get_ambiant_col(t_color obj_c, t_color amb_col, double intens)
{
	t_color	value;

	value.part1 = obj_c.part1 * amb_col.part1 * intens;
	value.part2 = obj_c.part2 * amb_col.part2 * intens;
	value.part3 = obj_c.part3 * amb_col.part3 * intens;
	return (value);
}

static t_color	get_diff_color(t_color o_c, double i, t_vector s_n, t_vector v)
{
	t_color	value;
	double	scalar;

	scalar = dot_product(s_n, v);
	value.part1 = 0;
	value.part2 = 0;
	value.part3 = 0;
	if (scalar < 0)
		return (value);
	value.part1 = i * scalar * o_c.part1;
	value.part2 = i * scalar * o_c.part2;
	value.part3 = i * scalar * o_c.part3;
	return (value);
}

t_color	pl_all_color_extend(double scalar1, double scalar2,
								t_scene *s, t_color pl_col)
{
	t_color	value;

	value.part1 = 0;
	value.part2 = 0;
	value.part3 = 0;
	if (!((scalar1 < 0 && scalar2 < 0) || (scalar1 > 0 && scalar2 > 0)))
		return (get_ambiant_col(pl_col, s->ambiant.color,
				s->ambiant.intensity));
	if (scalar1 < 0)
		scalar1 *= -1;
	value.part1 = s->light.intensity * scalar1
		* pl_col.part1 * s->light.color.part1;
	value.part2 = s->light.intensity * scalar1
		* pl_col.part2 * s->light.color.part2;
	value.part3 = s->light.intensity * scalar1
		* pl_col.part3 * s->light.color.part3;
	return (add_color(get_ambiant_col(pl_col, s->ambiant.color,
				s->ambiant.intensity), value));
}

t_color	pl_all_color(t_colision *c, t_scene *s, t_point inter, t_vector v)
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
	scalar2 = dot_product(s_n, substract_vect(s->light.origin, inter, inter));
	return (pl_all_color_extend(scalar1, scalar2, s, pl_col));
}

t_color	get_all_col(t_scene *s, t_colision *col, t_vector v,
		t_point inter)
{
	t_color		obj_col;
	t_vector	s_n;
	double		a;
	double		d;

	s_n = get_norm_surf(col->obj, col->type, inter);
	d = 1 / (1 + 0.00005 * distance(inter, s->light.origin)
			+ 0.000005 * pow(distance(inter, s->light.origin), 2));
	a = double_min(1, d);
	if (ft_strcmp(col->type, "sp") == 0)
		obj_col = ((t_sphere *)col->obj)->color;
	else if (ft_strcmp(col->type, "pl") == 0)
		return (pl_all_color(col, s, inter, v));
	else if (ft_strcmp(col->type, "cy") == 0 && !col->cap)
		obj_col = ((t_cylinder *)col->obj)->color;
	else if (ft_strcmp(col->type, "cy") == 0 && col->cap)
		return (pl_all_color(col, s, inter, v));
	obj_col = add_color(get_ambiant_col(obj_col, s->ambiant.color,
				s->ambiant.intensity), k_color(a, get_diff_color(obj_col,
					s->light.intensity, s_n, v)));
	return (obj_col);
}
