/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_light_suite.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:43:44 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/05 14:33:21 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_color	get_just_amb(t_scene *s, t_colision *col)
{
	t_color	obj_col;

	if (ft_strcmp(col->type, "sp") == 0)
		obj_col = ((t_sphere *)col->obj)->color;
	else if (ft_strcmp(col->type, "pl") == 0)
		obj_col = ((t_plan *)col->obj)->color;
	else if (ft_strcmp(col->type, "cy") == 0)
		obj_col = ((t_cylinder *)col->obj)->color;
	obj_col.part1 = obj_col.part1 * s->ambiant.color.part1
		* s->ambiant.intensity;
	obj_col.part2 = obj_col.part2 * s->ambiant.color.part2
		* s->ambiant.intensity;
	obj_col.part3 = obj_col.part3 * s->ambiant.color.part3
		* s->ambiant.intensity;
	return (obj_col);
}

void	intersect_light(t_scene *s, t_colision *c, t_point inter, t_scr_p p)
{
	t_colision	c_temp;
	t_vector	vec;

	vec = substract_vect(s->light.origin, inter, inter);
	c_temp.dist = INT_MAX;
	c_temp.type[0] = '\0';
	c_temp.obj = NULL;
	vec = normalisation(vec);
	sphere_int_l(vec, &s->sphere, &c_temp);
	plan_int_l(vec, &s->plan, &c_temp);
	cyl_int(vec, &s->cylinder, &c_temp);
	if (c_temp.dist >= distance(inter, s->light.origin))
		my_put_pixel(p.x, p.y, convert_color(get_all_col(s, c, vec, inter)), s);
	else
		my_put_pixel(p.x, p.y, convert_color(get_just_amb(s, c)), s);
}
