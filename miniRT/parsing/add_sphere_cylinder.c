/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere_cylinder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:47:06 by fifrandr          #+#    #+#             */
/*   Updated: 2025/02/11 10:05:39 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

static t_sphere_list	*create_sphere_node(char *line)
{
	t_sphere_list	*new_node;

	new_node = malloc(sizeof(t_sphere_list));
	if (!new_node)
		return (NULL);
	new_node->sphere = malloc(sizeof(t_sphere));
	if (!new_node->sphere)
	{
		free(new_node);
		return (NULL);
	}
	if (!parse_sphere(line, new_node->sphere))
	{
		free(new_node->sphere);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

int	add_sphere(t_scene *scene, char *line)
{
	t_sphere_list	*new_node;
	t_sphere_list	*temp;

	new_node = create_sphere_node(line);
	if (!new_node)
		return (0);
	if (!scene->sphere)
		scene->sphere = new_node;
	else
	{
		temp = scene->sphere;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	scene->nb_sphere++;
	return (1);
}

static t_cylinder_list	*create_cylinder_node(char *line)
{
	t_cylinder_list	*new_node;

	new_node = malloc(sizeof(t_cylinder_list));
	if (!new_node)
		return (NULL);
	new_node->cylinder = malloc(sizeof(t_cylinder));
	if (!new_node->cylinder)
	{
		free(new_node);
		return (NULL);
	}
	if (!parse_cylinder(line, new_node->cylinder))
	{
		free(new_node->cylinder);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

int	add_cylinder(t_scene *scene, char *line)
{
	t_cylinder_list	*new_node;
	t_cylinder_list	*temp;

	new_node = create_cylinder_node(line);
	if (!new_node)
		return (0);
	if (!scene->cylinder)
		scene->cylinder = new_node;
	else
	{
		temp = scene->cylinder;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
	scene->nb_cylinder++;
	return (1);
}
