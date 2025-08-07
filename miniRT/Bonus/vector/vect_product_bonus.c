/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_product_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:03:21 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/05 13:49:47 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

t_point	to_point(t_vector vec)
{
	t_point	point;

	point.x_p = vec.x_d;
	point.y_p = vec.y_d;
	point.z_p = vec.z_d;
	return (point);
}

double	dot_product(t_vector a, t_vector b)
{
	return (a.x_d * b.x_d + a.y_d * b.y_d + a.z_d * b.z_d);
}

t_vector	cross_product(t_vector a, t_vector b)
{
	t_vector	value;

	value.x_d = a.y_d * b.z_d - a.z_d * b.y_d;
	value.y_d = a.z_d * b.x_d - a.x_d * b.z_d;
	value.z_d = a.x_d * b.y_d - a.y_d * b.x_d;
	value.origin_d = a.origin_d;
	return (value);
}

t_vector	add_vector(t_vector a, t_vector b, t_point origin)
{
	t_vector	vec;

	vec.origin_d = origin;
	vec.x_d = a.x_d + b.x_d;
	vec.y_d = a.y_d + b.y_d;
	vec.z_d = a.z_d + b.z_d;
	return (vec);
}

t_vector	substract_vect(t_point a, t_point b, t_point origin)
{
	t_vector	vec;

	vec.x_d = a.x_p - b.x_p;
	vec.y_d = a.y_p - b.y_p;
	vec.z_d = a.z_p - b.z_p;
	vec.origin_d = origin;
	return (vec);
}
