/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_screen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:39:35 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/14 15:39:08 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	get_real_screen(t_scene *scene)
{
	int	width;
	double	theta;

	width = scene->win->width;
	theta = 0;
	theta = scene->camera.field_of_view * PI / 180;
	scene->dist_px_real = 2 * (scene->screen_cam_dist * tan(theta / 2)) / width;
}
