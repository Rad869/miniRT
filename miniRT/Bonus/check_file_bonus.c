/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:10:57 by fifrandr          #+#    #+#             */
/*   Updated: 2025/03/05 13:50:51 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/miniRT_bonus.h"

char	*check_point(char *av)
{
	if (ft_strlen(av) <= 3)
		return (NULL);
	if (ft_strchr(av, '.'))
		return (ft_strchr(av, '.'));
	return (NULL);
}

char	*check_identifier(char *av, char c)
{
	if (ft_strchr(av, c))
		return (ft_strchr(av, c));
	return (NULL);
}

void	msg_error(char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	check_format(char *av)
{
	if (check_point(av) == NULL)
		return (0);
	if (ft_strcmp(check_point(av), ".rt") == 0)
		return (1);
	return (0);
}
