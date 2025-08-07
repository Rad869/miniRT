/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows_suite2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:51:36 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/07 21:41:44 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

int	init_window(t_data *data, t_scene *scene)
{
	data->width = SCREEN_WIDTH;
	data->heigth = SCREEN_HEIGHT;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, data->width, data->heigth, "miniRT");
	data->img = mlx_new_image(data->mlx, data->width, data->heigth);
	data->addrs = mlx_get_data_addr(data->img, &data->bpp, &data->ll, &data->e);
	if (!data->win)
	{
		free(data->mlx);
		return (0);
	}
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_keypress, scene);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask,
		close_window, scene);
	mlx_mouse_hook(data->win, handle_mouse, scene);
	scene->win = data;
	get_real_screen(scene);
	return (1);
}
