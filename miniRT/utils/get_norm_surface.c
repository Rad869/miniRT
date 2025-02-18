/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_norm_surface.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:47:47 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/18 21:36:58 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_vector	get_norm_sp(t_sphere *sp, t_point pos)
{
	t_vector	vec;

	vec.x_d = pos.x_p - sp->origin.x_p;
	vec.y_d = pos.y_p - sp->origin.y_p;
	vec.z_d = pos.z_p - sp->origin.z_p;
	vec.origin_d = pos;
	return (normalisation(vec));
}

static t_vector	get_norm_cyl(t_cylinder *cyl, t_point pos)
{
	t_vector	CP;
	t_vector	norm;
	t_vector	proj;

	CP.x_d = pos.x_p - cyl->origin.x_p;
	CP.y_d = pos.y_p - cyl->origin.y_p;
	CP.z_d = pos.z_p - cyl->origin.z_p;
	cyl->orientation = normalisation(cyl->orientation);
	proj = k_vector(dot_product(CP, cyl->orientation), cyl->orientation);
	norm = substract_vect(to_point(CP), to_point(proj), pos);
	return (normalisation(norm));
}

t_vector	get_norm_surf(void *obj, char *type, t_point pos)
{
	t_vector	norm;

	if (ft_strcmp(type, "sp") == 0)
		norm = get_norm_sp((t_sphere *) obj, pos);
	else if (ft_strcmp(type, "cy") == 0)
		norm = get_norm_cyl((t_cylinder *) obj, pos);
	else if (ft_strcmp(type, "pl") == 0)
		norm = normalisation(((t_plan *) obj)->normal_vect);
	return (norm);
}