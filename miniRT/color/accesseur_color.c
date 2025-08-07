/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accesseur_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:57:32 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/24 12:43:55 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	convert_color(t_color col)
{
	int	value;
	int	r;
	int	g;
	int	b;

	value = 0;
	r = col.part1 * 255;
	g = col.part2 * 255;
	b = col.part3 * 255;
	value = ((r << 16) & 0xff0000) | ((g << 8) & 0x00ff00) | ((b & 0x0000ff));
	return (value);
}

t_color	add_color(t_color c1, t_color c2)
{
	t_color	value;

	value.part1 = double_min(c1.part1 + c2.part1, 1);
	value.part2 = double_min(c1.part2 + c2.part2, 1);
	value.part3 = double_min(c1.part3 + c2.part3, 1);
	return (value);
}

t_color	k_color(double k, t_color c)
{
	t_color	col;

	col.part1 = double_min(c.part1 * k, 1);
	col.part2 = double_min(c.part2 * k, 1);
	col.part3 = double_min(c.part3 * k, 1);
	return (col);
}
