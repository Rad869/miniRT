/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:36:27 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/02 10:53:49 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_scene	*init_scene(void)
{
	t_scene	*scene;

	scene = malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->sphere = NULL;
	scene->cylinder = NULL;
	scene->plan = NULL;
	scene->nb_sphere = 0;
	scene->nb_cylinder = 0;
	scene->nb_plan = 0;
	scene->screen_cam_dist = 0.1;
	scene->dist_px_real = 0.0;
	scene->win = NULL;
	scene->mode = MODE_CAMERA;
	scene->selected_obj = NULL;
	ft_memset(&scene->camera, 0, sizeof(t_camera));
	ft_memset(&scene->ambiant, 0, sizeof(t_aLight));
	ft_memset(&scene->light, 0, sizeof(t_light));
	return (scene);
}
