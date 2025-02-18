/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalisation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:06:21 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/18 06:24:58 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	normalisation(t_vector vector)
{
	t_vector	value;
	double		module;

	module = ft_module(vector);
	value.origin_d.x_p = vector.origin_d.x_p;
	value.origin_d.y_p = vector.origin_d.y_p;
	value.origin_d.z_p = vector.origin_d.z_p;
	value.x_d = 0;
	value.y_d = 0;
	value.z_d = 0;
	if (module != 0)
	{
		value.x_d = vector.x_d / module;
		value.y_d = vector.y_d / module;
		value.z_d = vector.z_d / module;
	}
	return (value);
}

double	ft_module(t_vector vector)
{
	double	x;
	double	y;
	double	z;

	x = pow(vector.x_d, 2);
	y = pow(vector.y_d, 2);
	z = pow(vector.z_d, 2);
	return (sqrt(x + y + z));
}

double	distance(t_point a, t_point b)
{
	double	x;
	double	y;
	double	z;

	x = pow(a.x_p - b.x_p, 2);
	y = pow(a.y_p - b.y_p, 2);
	z = pow(a.z_p - b.z_p, 2);
	return (sqrt(x + y + z));
}

t_vector	director_vect(t_point a, t_point b)
{
	t_vector	value;

	value.origin_d.x_p = a.x_p;
	value.origin_d.y_p = a.y_p;
	value.origin_d.z_p = a.z_p;
	value.x_d = b.x_p;
	value.y_d = b.y_p;
	value.z_d = b.z_p;
	value = normalisation(value);
	return (value);
}

t_vector	to_vector(t_point p, t_point origin)
{
	t_vector	vec;

	vec.origin_d = origin;
	vec.x_d = p.x_p;
	vec.y_d = p.y_p;
	vec.z_d = p.z_p;
	return (vec);
}
