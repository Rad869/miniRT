/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:42:48 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/08 02:51:14 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT_bonus.h"
#include <stdio.h>

int	open_file(char *filename)
{
	int	op;

	op = open(filename, O_RDONLY);
	if (op == -1)
	{
		msg_error("Open file error");
		return (-1);
	}
	return (op);
}

int	is_error(char *line)
{
	free(line);
	return (0);
}

int	validate_mapp(int op, t_map_elements *elements)
{
	char	*line;

	while (1)
	{
		line = get_next_line(op);
		if (line == NULL)
			break ;
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue ;
		}
		if (!update_map_elements(line, elements))
			return (is_error(line));
		free(line);
	}
	if (!check_map_elements(elements))
	{
		msg_error("Error\n Element(s) number error\n");
		return (0);
	}
	return (1);
}

int	parse_scene(int op, t_scene *scene)
{
	char	*line;

	while (1)
	{
		line = get_next_line(op);
		if (line == NULL)
			break ;
		if (ft_strchr(line, 'C'))
			parse_camera(line, &scene->camera);
		else if (ft_strchr(line, 'A'))
			parse_ambient(line, &scene->ambiant);
		else if (ft_strchr(line, 's'))
			add_sphere(scene, line);
		else if (ft_strchr(line, 'c'))
			add_cylinder(scene, line);
		else if (ft_strchr(line, 'p'))
			add_plane(scene, line);
		else if (ft_strchr(line, 'm'))
			add_light(scene, line);
		free(line);
	}
	compute_cam_angle(scene);
	return (1);
}

int	main(int ac, char **av)
{
	int				op;
	t_data			data;
	t_map_elements	elements;
	t_scene			*scene;

	if (ac != 2 || !check_format(av[1]))
		return (msg_error("Error\nArgument error\n"), 0);
	init_map_elements(&elements);
	op = open_file(av[1]);
	if (op == -1)
		return (0);
	if (!validate_mapp(op, &elements))
		return (0);
	close(op);
	op = open_file(av[1]);
	if (op == -1)
		return (0);
	scene = init_scene();
	parse_scene(op, scene);
	close(op);
	if (!init_window(&data, scene))
		msg_error("Error\nWindows error\n");
	intersect_show(scene);
	mlx_loop(data.mlx);
	return (0);
}
