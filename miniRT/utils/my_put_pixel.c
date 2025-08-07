/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:14:25 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/24 13:27:41 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	my_put_pixel(int x, int y, int color, t_scene *scene)
{
	char	*destination;
	char	*addr;
	int		ll;
	int		bpp;

	if (x >= 0 && x <= scene->win->width && y >= 0 && y <= scene->win->heigth)
	{
		addr = scene->win->addrs;
		ll = scene->win->ll;
		bpp = scene->win->bpp;
		destination = addr + (y * ll + x * (bpp / 8));
		*(unsigned int *) destination = color;
	}
}
