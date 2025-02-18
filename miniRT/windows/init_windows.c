/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:49:10 by fifrandr          #+#    #+#             */
/*   Updated: 2025/02/14 15:22:59 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}

int handle_keypress(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        close_window(data);
    return (0);
}

int init_window(t_data *data, t_scene *scene)
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
    mlx_hook(data->win, KeyPress, KeyPressMask, handle_keypress, data);
    mlx_hook(data->win, DestroyNotify, StructureNotifyMask, close_window, data);
    scene->win = data;
    get_real_screen(scene);
    return (1);
}
