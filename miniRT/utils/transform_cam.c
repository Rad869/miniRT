/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:34:51 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/16 14:48:19 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	transform_cam(t_scene *scene, t_vector vec)
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
	vec.x_d = x * cos(phi) + z * sin(phi);
	vec.y_d = x * sin(phi) * sin(theta) + y * cos(theta) - z * cos(phi) * sin(theta);
	vec.z_d = -x * sin(phi) * cos(theta) + y * sin(theta) + z * cos(phi) * cos(theta);
	return(vec);
}
