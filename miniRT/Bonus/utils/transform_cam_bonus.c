/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_cam_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:34:51 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/07 21:55:16 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

t_vector	transform_cam(t_scene *scene, t_vector vec, double rho)
{
	double	x;
	double	y;
	double	z;
	double	theta;
	double	phi;

	x = vec.x_d;
	y = vec.y_d;
	z = vec.z_d;
	theta = scene->camera.theta;
	phi = scene->camera.phi;
	vec.x_d = x * cos(phi) * cos(rho) + z * sin(phi) - y * sin(rho) * cos(phi);
	vec.y_d = x * (cos(rho) * sin(phi) * sin(theta) + sin(rho) * cos(theta)) - z
		* cos(phi) * sin(theta) - y * (sin(rho) * sin(phi) * sin(theta)
			- cos(theta) * cos(rho));
	vec.z_d = -x * (cos(rho) * sin(phi)
			* cos(theta) - sin(rho) * sin(theta)) + z
		* cos(phi) * cos(theta) + y * (sin(phi) * sin(rho) * cos(theta)
			+ cos(rho) * sin(theta));
	return (vec);
}
