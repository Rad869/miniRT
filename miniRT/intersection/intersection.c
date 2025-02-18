/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:34:51 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/18 07:27:25 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	intersection(t_scene *scene, t_colision *col, t_vector vec, t_scr_p p)
{
	col->obj = (void *) NULL;
	col->dist = INT_MAX;
	col->type[0] = '\0';
	vec = normalisation(vec);
	sphere_int(vec, &scene->sphere, col);
	plan_int(vec, &scene->plan, col);
	cyl_int(vec, &scene->cylinder, col);
	if (col->dist < INT_MAX)
	{
		if (ft_strcmp(col->type, "sp") == 0)
			my_put_pixel(p.x, p.y, 0xff10ff, scene);
		else if (ft_strcmp(col->type, "pl") == 0)
			my_put_pixel(p.x, p.y, 0x00ffff, scene);
		else if (ft_strcmp(col->type, "cy") == 0)
			my_put_pixel(p.x, p.y, 0x00ff00, scene);
	}
	else
		my_put_pixel(p.x, p.y, 0x000000, scene);
}
