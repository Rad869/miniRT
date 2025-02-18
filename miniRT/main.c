/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 09:42:48 by fifrandr          #+#    #+#             */
/*   Updated: 2025/02/18 07:33:47 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"
#include <stdio.h>

int open_file(char *filename)
{
    int op;

    op = open(filename, O_RDONLY);
    if (op == -1)
    {
        msg_error("Open file error");
        return (-1);
    }
    return (op);
}

int validate_mapp(int op, t_map_elements *elements)
{
    char *line;

    while((line = get_next_line(op)) != NULL)
    {
        if (line[0] == '\n' || line[0] == '\0')
        {
            free(line);
            continue;
        }
        if (!update_map_elements(line, elements))
        {
            free(line);
            msg_error("error map");
            return (0);
        }
        free(line);
    }
    if (!check_map_elements(elements))
    {
        msg_error("error map");
        return (0);
    }
    return (1);
}


int parse_scene(int op, t_scene *scene)
{
    char *line;

    while ((line = get_next_line(op)) != NULL)
    {
        if (line[0] == 'C')
            parse_camera(line, &scene->camera);
        else if (line[0] == 'L')
            parse_light(line, &scene->light);
        else if (line[0] == 'A')
            parse_ambient(line, &scene->ambiant);
        else if (ft_strncmp(line, "sp", 2) == 0)
            add_sphere(scene, line);
        else if (ft_strncmp(line, "cy", 2) == 0)
            add_cylinder(scene, line);
        else if (ft_strncmp(line, "pl", 2) == 0)
            add_plane(scene, line);
        free(line);
    }
    compute_cam_angle(scene);
    return (1);
}

int main(int ac, char **av)
{
    int op;
    t_data  data;
    t_map_elements elements;
    t_scene *scene;

    if (ac != 2 || !check_format(av[1]))
    {
        msg_error("verifiez les arguments");
        return (0);
    }
    scene = init_scene();
    init_map_elements(&elements);
    if ((op = open_file(av[1])) == -1)
        return (0);
    if (!validate_mapp(op, &elements))
        return (0);
    close(op);
    if ((op = open_file(av[1])) == -1)
        return (0);
    parse_scene(op, scene);
    close(op);
    if (!init_window(&data, scene))
        msg_error("Windows error");
    intersect_show(scene);
    printf("cyl diam = %lf height = %lf\n", scene->cylinder->cylinder->diameter, scene->cylinder->cylinder->height);
    mlx_put_image_to_window(scene->win->mlx, scene->win->win, scene->win->img, 0, 0);
    mlx_loop(data.mlx);
    return (0);
}
