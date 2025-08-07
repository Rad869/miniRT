/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:07:57 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/05 13:49:47 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT_bonus.h"

int	points_seen(char *str, int i)
{
	int	point_seen;

	point_seen = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (point_seen || (!ft_isdigit(str[i - 1])
					|| !ft_isdigit(str[i + 1])))
			{
				free(str);
				return (0);
			}
			point_seen = 1;
		}
		else if (!ft_isdigit(str[i]))
		{
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sphere_arg(char **line_splited)
{
	double	diameter;

	if (ft_strcmp(line_splited[0], "sp") != 0
		|| !check_coordinates(line_splited[1]) || !num_digitt(line_splited[2])
		|| !check_color(line_splited[3]))
	{
		ft_free_split(line_splited);
		return (0);
	}
	diameter = ft_atof(line_splited[2]);
	if (diameter <= 0)
	{
		ft_free_split(line_splited);
		return (0);
	}
	return (1);
}

int	check_sphere(char *line)
{
	char	**line_splited;
	char	*cleaned;

	cleaned = ft_strdup(line);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	if (count_arguments(cleaned) != 4)
	{
		printf("Error\nIn the sphere mapping\n");
		free(cleaned);
		return (0);
	}
	line_splited = ft_split(cleaned, ' ');
	free(cleaned);
	if (!line_splited)
		return (0);
	if (check_sphere_arg(line_splited) == 0)
	{
		printf("Error\nIn the sphere mapping\n");
		return (0);
	}
	ft_free_split(line_splited);
	return (1);
}
