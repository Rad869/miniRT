/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:09:49 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/02 12:34:49 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	num_digitt(char *str)
{
	int		i;
	char	*cleaned;

	if (!str)
		return (0);
	cleaned = ft_strdup(str);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	i = 0;
	if (cleaned[i] == '+' || cleaned[i] == '-')
		i++;
	if (points_seen(cleaned, i) == 0)
		return (0);
	free(cleaned);
	return (1);
}

int	num_digitt2(char *str)
{
	int		i;
	char	*cleaned;

	if (!str)
		return (0);
	cleaned = ft_strdup(str);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	i = 0;
	if (cleaned[i] == '+' || cleaned[i] == '-')
		i++;
	while (cleaned[i])
	{
		if (!ft_isdigit(cleaned[i]))
		{
			free(cleaned);
			return (0);
		}
		i++;
	}
	free(cleaned);
	return (1);
}

int	check_cylinder_arg(char **line_splited)
{
	double	diameter;
	double	height;

	if (ft_strcmp(line_splited[0], "cy") != 0
		|| !check_coordinates(line_splited[1])
		|| !check_normalized_vector(line_splited[2])
		|| !num_digitt(line_splited[3]) || !num_digitt(line_splited[4])
		|| !check_color(line_splited[5]))
	{
		ft_free_split(line_splited);
		return (0);
	}
	diameter = ft_atof(line_splited[3]);
	height = ft_atof(line_splited[4]);
	if (diameter <= 0 || height <= 0)
	{
		ft_free_split(line_splited);
		return (0);
	}
	return (1);
}

int	check_cylinder(char *line)
{
	char	**line_splited;
	char	*cleaned;

	cleaned = ft_strdup(line);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	if (count_arguments(cleaned) != 6)
	{
		printf("Error\nIn the cylinder mapping\n");
		free(cleaned);
		return (0);
	}
	line_splited = ft_split(cleaned, ' ');
	free(cleaned);
	if (!line_splited)
		return (0);
	if (check_cylinder_arg(line_splited) == 0)
	{
		printf("Error\nIn the cylinder mapping\n");
		return (0);
	}
	ft_free_split(line_splited);
	return (1);
}
