/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:30:53 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/07 22:25:55 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static void	free_scene_extend(t_scene *scene)
{
	t_sphere_list	*tmp_s;

	while (scene->sphere)
	{
		tmp_s = scene->sphere;
		scene->sphere = scene->sphere->next;
		free(tmp_s->sphere);
		free(tmp_s);
	}
}

void	free_scene(t_scene *scene)
{
	t_cylinder_list	*tmp_c;
	t_plane_list	*tmp_p;

	while (scene->cylinder)
	{
		tmp_c = scene->cylinder;
		scene->cylinder = scene->cylinder->next;
		free(tmp_c->cylinder);
		free(tmp_c);
	}
	while (scene->plan)
	{
		tmp_p = scene->plan;
		scene->plan = scene->plan->next;
		free(tmp_p->plane);
		free(tmp_p);
	}
	free_scene_extend(scene);
	free(scene);
}
