/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:10 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/07 19:45:21 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

int	close_window(t_scene *data)
{
	mlx_destroy_image(data->win->mlx, data->win->img);
	mlx_destroy_window(data->win->mlx, data->win->win);
	mlx_destroy_display(data->win->mlx);
	free(data->win->mlx);
	free_scene(data);
	exit(0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_scene *scene)
{
	t_vector	vec;
	t_colision	col;

	if (button == 1)
	{
		vec.origin_d = scene->camera.origin;
		vec.z_d = scene->screen_cam_dist;
		vec.y_d = -(scene->dist_px_real * scene->win->heigth)
			/ 2 + y * scene->dist_px_real;
		vec.x_d = -(scene->dist_px_real * scene->win->width)
			/ 2 + x * scene->dist_px_real;
		vec = normalisation(vec);
		intersection(scene, &col, transform_cam(scene, vec,
				scene->camera.rho), (t_scr_p){x, y});
		if (col.obj != NULL)
		{
			if (scene->selected_obj != NULL)
				free(scene->selected_obj);
			scene->selected_obj = malloc(sizeof(t_colision));
			if (scene->selected_obj)
				*(scene->selected_obj) = col;
			printf("Objet sélectionné : %s\n", scene->selected_obj->type);
		}
	}
	return (0);
}

void	move_selected_sphere(t_scene *scene, int keysym)
{
	t_sphere	*sp;

	sp = (t_sphere *)scene->selected_obj->obj;
	if (keysym == XK_Left)
		sp->origin.x_p -= 5.0;
	else if (keysym == XK_Right)
		sp->origin.x_p += 5.0;
	else if (keysym == XK_Up)
		sp->origin.y_p += 5.0;
	else if (keysym == XK_Down)
		sp->origin.y_p -= 5.0;
	else if (keysym == 'w')
		sp->origin.z_p += 5.0;
	else if (keysym == 's')
		sp->origin.z_p -= 5.0;
	else if (keysym == 65453)
	{
		if (sp->radius <= 1)
			printf("Warning: rayon negatif ou null\n");
		else
			sp->radius -= 1;
	}
	else if (keysym == 65451)
		sp->radius += 1;
}

void	move_selected_cylinder_suite(t_cylinder *cy, int keysym)
{
	if (keysym == 65453)
	{
		if (cy->height <= 1)
			printf("Warning: hauteur negatif ou null\n");
		else
			cy->height -= 1;
	}
	else if (keysym == 65451)
		cy->height += 1;
	else if (keysym == 65430)
	{
		if (cy->diameter <= 1)
			printf("Warning: diametre negatif ou null\n");
		else
			cy->diameter -= 1;
	}
	else if (keysym == 65432)
		cy->diameter += 1;
}

void	move_selected_cylinder(t_scene *scene, int keysym)
{
	t_cylinder	*cy;

	cy = (t_cylinder *)scene->selected_obj->obj;
	if (keysym == XK_Left)
		cy->origin.x_p -= 5.0;
	else if (keysym == XK_Right)
		cy->origin.x_p += 5.0;
	else if (keysym == XK_Up)
		cy->origin.y_p += 5.0;
	else if (keysym == XK_Down)
		cy->origin.y_p -= 5.0;
	else if (keysym == 'w')
		cy->origin.z_p += 5.0;
	else if (keysym == 's')
		cy->origin.z_p -= 5.0;
	else if (keysym == 'q')
		cy->a += (5 * PI) / 180;
	else if (keysym == 'e')
		cy->a -= (5 * PI) / 180;
	else if (keysym == 'a')
		cy->b += (5 * PI) / 180;
	else if (keysym == 'd')
		cy->b -= (5 * PI) / 180;
	else
		move_selected_cylinder_suite(cy, keysym);
}
