/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:25:38 by fifrandr          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:42 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	pos;

	pos = 0;
	while (s[pos])
	{
		(*f)(pos, &s[pos]);
		pos++;
	}
}
