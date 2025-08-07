/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cam_angle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:03:48 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/24 13:24:09 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static void	theta_phi_random(t_vector vec, double *theta, double *phi)
{
	double	additional;

	additional = 0;
	*theta = -atan(vec.y_d / vec.z_d);
	*phi = -atan(vec.x_d * sin(*theta) / vec.y_d);
	if (vec.z_d < 0)
		additional = PI;
	*phi += additional;
	if (*phi > 2 * PI)
		*phi -= 2 * PI;
}

static void	get_theta_phi(t_vector vec, double *theta, double *phi)
{
	t_vector	n_vec;

	n_vec = normalisation(vec);
	if (n_vec.x_d != 0 && n_vec.y_d == 0 && n_vec.z_d == 0)
	{
		*theta = 0;
		*phi = asin(n_vec.x_d);
	}
	else if (n_vec.x_d == 0 && n_vec.y_d != 0 && n_vec.z_d == 0)
	{
		*phi = 0;
		*theta = -asin(n_vec.y_d);
	}
	else if (n_vec.x_d == 0 && n_vec.y_d == 0 && n_vec.z_d != 0)
	{
		*phi = 0;
		*theta = acos(n_vec.z_d);
	}
	else
		theta_phi_random(n_vec, theta, phi);
}

void	compute_cam_angle(t_scene *scene)
{
	t_camera	*cam;

	cam = &scene->camera;
	get_theta_phi(cam->orientation, &cam->theta, &cam->phi);
	cam->rho = 0;
}
