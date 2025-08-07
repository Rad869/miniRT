/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_resolution_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:59:00 by rrabeari          #+#    #+#             */
/*   Updated: 2025/03/05 13:49:47 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

double	double_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	quadratique_equation(double a, double b, double c)
{
	double	delta;
	double	result1;
	double	result2;

	result1 = 0;
	result2 = 0;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (-1);
	else if (delta == 0)
		return (-b / (2 * a));
	else
	{
		result1 = (-b - sqrt(delta)) / (2 * a);
		result2 = (-b + sqrt(delta)) / (2 * a);
		if (result1 > 0 && result2 > 0)
			return (double_min(result1, result2));
		else if (result1 <= 0 && result2 > 0)
			return (result2);
		else if (result2 <= 0 && result1 > 0)
			return (result1);
	}
	return (-1);
}

t_vector	k_vector(double k, t_vector vec)
{
	vec.x_d = vec.x_d * k;
	vec.y_d = vec.y_d * k;
	vec.z_d = vec.z_d * k;
	return (vec);
}
