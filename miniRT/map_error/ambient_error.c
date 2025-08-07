/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:03:52 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:22 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	check_color_nbr(char **color_splited)
{
	if (((ft_atoi(color_splited[0]) < 0) || (ft_atoi(color_splited[0]) > 255))
		|| (num_digitt2(color_splited[0]) == 0))
	{
		ft_free_split(color_splited);
		return (0);
	}
	if (((ft_atoi(color_splited[1]) < 0) || (ft_atoi(color_splited[1]) > 255))
		|| (num_digitt2(color_splited[1]) == 0))
	{
		ft_free_split(color_splited);
		return (0);
	}
	if (((ft_atoi(color_splited[2]) < 0) || (ft_atoi(color_splited[2]) > 255))
		|| (num_digitt2(color_splited[2]) == 0))
	{
		ft_free_split(color_splited);
		return (0);
	}
	return (1);
}

int	check_color(char *line)
{
	char	**color_splited;
	char	*cleaned;

	cleaned = ft_strdup(line);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	if (count_comma_separated(cleaned) != 3)
	{
		free(cleaned);
		return (0);
	}
	color_splited = ft_split(cleaned, ',');
	free(cleaned);
	if (!color_splited)
		return (0);
	if (check_color_nbr(color_splited) == 0)
		return (0);
	ft_free_split(color_splited);
	return (1);
}

int	ambient_light_check(char **line_splited)
{
	if (ft_strcmp(line_splited[0], "A") != 0)
	{
		ft_free_split(line_splited);
		return (0);
	}
	if (((ft_atof(line_splited[1]) < 0) || (ft_atof(line_splited[1]) > 1))
		|| num_digitt(line_splited[1]) == 0)
	{
		ft_free_split(line_splited);
		return (0);
	}
	if (check_color(line_splited[2]) == 0)
	{
		ft_free_split(line_splited);
		return (0);
	}
	return (1);
}

int	ambient_ligth(char *line)
{
	char	**line_splited;
	char	*cleaned;

	cleaned = ft_strdup(line);
	if (!cleaned)
		return (0);
	clean_line(cleaned);
	if (count_arguments(cleaned) != 3)
	{
		printf("Error\nIn the ambient mapping\n");
		free(cleaned);
		return (0);
	}
	line_splited = ft_split(cleaned, ' ');
	free(cleaned);
	if (!line_splited)
		return (0);
	if (ambient_light_check(line_splited) == 0)
	{
		printf("Error\nIn the ambient mapping\n");
		return (0);
	}
	ft_free_split(line_splited);
	return (1);
}
