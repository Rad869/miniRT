/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_resolution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:59:00 by rrabeari          #+#    #+#             */
/*   Updated: 2025/02/18 07:01:55 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

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
		return (- b / (2 * a));
	else
	{
		result1 = (- b - sqrt(delta)) / (2 * a);
		result2 = (- b + sqrt(delta)) / (2 * a);
		if (result1 > 0 && result2 > 0)
			return (double_min(result1, result2));
		else if (result1 <= 0 && result2 > 0)
			return (result2);
		else if (result2 <= 0 && result1 > 0)
			return (result1);
	}
	return (-1);
}
