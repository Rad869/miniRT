/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows_suite_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:51:55 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/08 01:56:26 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

void	move_selected_plan(t_scene *scene, int keysym)
{
	t_plan	*pl;

	pl = (t_plan *)scene->selected_obj->obj;
	if (keysym == XK_Left)
		pl->origin.x_p -= 5.0;
	else if (keysym == XK_Right)
		pl->origin.x_p += 5.0;
	else if (keysym == XK_Up)
		pl->origin.y_p += 5.0;
	else if (keysym == XK_Down)
		pl->origin.y_p -= 5.0;
	else if (keysym == 'w')
		pl->origin.z_p += 5.0;
	else if (keysym == 's')
		pl->origin.z_p -= 5.0;
	else if (keysym == 'q')
		pl->a += (5 * PI) / 180;
	else if (keysym == 'e')
		pl->a -= (5 * PI) / 180;
	else if (keysym == 'a')
		pl->b += (5 * PI) / 180;
	else if (keysym == 'd')
		pl->b -= (5 * PI) / 180;
}

void	move_selected_object(t_scene *scene, int keysym)
{
	if (scene->selected_obj == NULL || scene->selected_obj->obj == NULL)
		return ;
	if (scene->selected_obj->type[0] == 's'
		&& scene->selected_obj->type[1] == 'p')
	{
		move_selected_sphere(scene, keysym);
	}
	else if (scene->selected_obj->type[0] == 'c'
		&& scene->selected_obj->type[1] == 'y')
	{
		move_selected_cylinder(scene, keysym);
	}
	else if (scene->selected_obj->type[0] == 'p'
		&& scene->selected_obj->type[1] == 'l')
	{
		move_selected_plan(scene, keysym);
	}
}

void	move_camera(t_scene *scene, int keysym)
{
	if (keysym == XK_Up)
		scene->camera.origin.y_p += 5.0;
	else if (keysym == XK_Down)
		scene->camera.origin.y_p -= 5.0;
	else if (keysym == XK_Right)
		scene->camera.origin.x_p += 5.0;
	else if (keysym == XK_Left)
		scene->camera.origin.x_p -= 5.0;
	else if (keysym == 'w')
		scene->camera.origin.z_p += 5.0;
	else if (keysym == 's')
		scene->camera.origin.z_p -= 5.0;
	else if (keysym == 'q')
		scene->camera.rho -= (10 * PI) / 180;
	else if (keysym == 'e')
		scene->camera.rho += (10 * PI) / 180;
	else if (keysym == 'z')
		scene->camera.phi -= (10 * PI) / 180;
	else if (keysym == 'v')
		scene->camera.phi += (10 * PI) / 180;
}

void	move_light(t_scene *scene, int keysym)
{
	if (scene->current_light == NULL)
		scene->current_light = scene->light;
	if (keysym == XK_Left)
		scene->current_light->light->origin.x_p -= 5.0;
	else if (keysym == XK_Right)
		scene->current_light->light->origin.x_p += 5.0;
	else if (keysym == XK_Up)
		scene->current_light->light->origin.y_p += 5.0;
	else if (keysym == XK_Down)
		scene->current_light->light->origin.y_p -= 5.0;
	else if (keysym == 'w')
		scene->current_light->light->origin.z_p += 5.0;
	else if (keysym == 's')
		scene->current_light->light->origin.z_p -= 5.0;
	else if (keysym == 'n')
	{
		if (scene->current_light->next != NULL)
			scene->current_light = scene->current_light->next;
		else
			scene->current_light = scene->light;
	}
}

int	handle_keypress(int keysym, t_scene *scene)
{
	if (keysym == XK_Escape)
		close_window(scene);
	if (keysym == 'c')
	{
		scene->mode = MODE_CAMERA;
		printf("Mode : Caméra\n");
	}
	else if (keysym == 'o')
	{
		scene->mode = MODE_OBJECT;
		printf("Mode : Objet\n");
	}
	else if (keysym == 'l')
	{
		scene->mode = MODE_LIGHT;
		printf("Mode : Lumière, press n for next\n");
	}
	if (scene->mode == MODE_CAMERA)
		move_camera(scene, keysym);
	else if (scene->mode == MODE_OBJECT)
		move_selected_object(scene, keysym);
	else if (scene->mode == MODE_LIGHT)
		move_light(scene, keysym);
	intersect_show(scene);
	return (0);
}
