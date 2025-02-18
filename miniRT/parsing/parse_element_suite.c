/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_suite.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:45:51 by fifrandr          #+#    #+#             */
/*   Updated: 2025/02/15 11:59:03 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int parse_light(char *line, t_light *light)
{
    char **parts;

    parts = ft_split(line, ' ');
    if (!parts)
        return (0);
    parse_point(parts[1], &light->origin);
    light->intensity = ft_atof(parts[2]);
    parse_color(parts[3], &light->color);
    ft_free_split(parts);
    return (1);
}

int parse_ambient(char *line, t_aLight *alight)
{
    char **parts;

    parts = ft_split(line, ' ');
    if (!parts)
        return (0);
    alight->intensity = ft_atof(parts[1]);
    parse_color(parts[2], &alight->color);
    ft_free_split(parts);
    return (1);
}

int parse_sphere(char *line, t_sphere *sphere)
{
    char **parts;

    parts = ft_split(line, ' ');
    if (!parts)
        return (0);
    parse_point(parts[1], &sphere->origin);
    sphere->radius = ft_atof(parts[2]) / 2.0;
    parse_color(parts[3], &sphere->color);
    ft_free_split(parts);
    return (1);
}

int parse_cylinder(char *line, t_cylinder *cylinder)
{
    char **parts;

    parts = ft_split(line, ' ');
    if (!parts)
        return (0);
    parse_point(parts[1], &cylinder->origin);
    parse_vector(parts[2], &cylinder->orientation);
    cylinder->orientation.origin_d = cylinder->origin;
    cylinder->diameter = ft_atof(parts[3]);
    cylinder->height = ft_atof(parts[4]);
    parse_color(parts[5], &cylinder->color);
    ft_free_split(parts);
    return (1);
}
