/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:21:17 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/02 12:22:30 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static double	handle_decimal_part(const char *str)
{
	double	decimal;
	double	factor;

	decimal = 0.0;
	factor = 1.0;
	if (*str != '.')
		return (0.0);
	str++;
	while (*str && *str >= '0' && *str <= '9')
	{
		factor /= 10.0;
		decimal += (*str - '0') * factor;
		str++;
	}
	return (decimal);
}

double	ft_atof(char *str)
{
	double	result;
	int		sign;

	result = 0.0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	result += handle_decimal_part(str);
	return (sign * result);
}

int	is_really_normalized(double x, double y, double z)
{
	double	a;
	double	b;
	double	c;
	double	result;

	a = pow(x, 2);
	b = pow(y, 2);
	c = pow(z, 2);
	result = sqrt(a + b + c);
	if (result >= 0.999 && result <= 1.001)
		return (1);
	printf("vecteur camera hors norme: %f\n", result);
	return (0);
}

int	parse_vector_values(char *str, double *x, double *y, double *z)
{
	char	**values;
	int		valid;

	if (!str || count_comma_separated(str) != 3)
		return (0);
	values = ft_split(str, ',');
	if (!values)
		return (0);
	valid = (num_digitt(values[0]) && num_digitt(values[1])
			&& num_digitt(values[2]) && !(ft_atof(values[0])
				== 0 && ft_atof(values[1]) == 0
				&& ft_atof(values[2]) == 0));
	if (!valid)
	{
		ft_free_split(values);
		return (0);
	}
	*x = ft_atof(values[0]);
	*y = ft_atof(values[1]);
	*z = ft_atof(values[2]);
	ft_free_split(values);
	return (1);
}
