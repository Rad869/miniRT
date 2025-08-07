/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_light_suite_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:43:44 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/07 21:52:15 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

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
	t_colision		c_temp;
	t_vector		vec;
	t_light_list	*light;
	t_color			tmp;

	light = s->light;
	tmp.part1 = 0;
	tmp.part2 = 0;
	tmp.part3 = 0;
	while (light != NULL)
	{
		vec = substract_vect(light->light->origin, inter, inter);
		c_temp.dist = INT_MAX;
		c_temp.type[0] = '\0';
		c_temp.obj = NULL;
		vec = normalisation(vec);
		sphere_int_l(vec, &s->sphere, &c_temp);
		plan_int_l(vec, &s->plan, &c_temp);
		cyl_int(vec, &s->cylinder, &c_temp);
		if (c_temp.dist >= distance(inter, light->light->origin))
			tmp = add_color(tmp, get_all_col(c, vec, inter, light->light));
		light = light->next;
	}
	tmp = add_color(get_just_amb(s, c), tmp);
	my_put_pixel(p.x, p.y, convert_color(tmp), s);
}
