/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:41:43 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/07 21:53:00 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

static void	free_other_object(t_scene *scene)
{
	t_cylinder_list	*tmp_c;
	t_light_list	*tmp_l;

	while (scene->cylinder)
	{
		tmp_c = scene->cylinder;
		scene->cylinder = scene->cylinder->next;
		free(tmp_c->cylinder);
		free(tmp_c);
	}
	while (scene->light)
	{
		tmp_l = scene->light;
		scene->light = scene->light->next;
		free(tmp_l->light);
		free(tmp_l);
	}
}

void	free_scene(t_scene *scene)
{
	t_sphere_list	*tmp_s;
	t_plane_list	*tmp_p;

	while (scene->sphere)
	{
		tmp_s = scene->sphere;
		scene->sphere = scene->sphere->next;
		free(tmp_s->sphere);
		free(tmp_s);
	}
	while (scene->plan)
	{
		tmp_p = scene->plan;
		scene->plan = scene->plan->next;
		free(tmp_p->plane);
		free(tmp_p);
	}
	free_other_object(scene);
	free(scene);
}
