/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:48:58 by fifrandr          #+#    #+#             */
/*   Updated: 2025/02/15 11:58:22 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_plane_list *create_plane_node(char *line)
{
    t_plane_list    *new_node;

    new_node = malloc(sizeof(t_plane_list));
    if (!new_node)
        return (NULL);
    new_node->plane = malloc(sizeof(t_plan));
    if (!new_node->plane)
    {
        free(new_node);
        return (NULL);
    }
    if (!parse_plane(line, new_node->plane))
    {
        free(new_node->plane);
        free(new_node);
        return (NULL);
    }
    new_node->next = NULL;
    return (new_node);
}

int add_plane(t_scene *scene, char *line)
{
    t_plane_list    *new_node;
    t_plane_list    *temp;

    new_node = create_plane_node(line);
    if (!new_node)
        return (0);

    if (!scene->plan)
        scene->plan = new_node;
    else
    {
        temp = scene->plan;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
    scene->nb_plan++;
    return (1);
}

int parse_plane(char *line, t_plan *plane)
{
    char **parts;

    parts = ft_split(line, ' ');
    if (!parts)
        return (0);
    parse_point(parts[1], &plane->origin);
    parse_vector(parts[2], &plane->normal_vect);
    plane->normal_vect.origin_d = plane->origin;
    parse_color(parts[3], &plane->color);
    ft_free_split(parts);
    return (1);
}
