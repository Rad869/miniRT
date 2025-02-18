/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:41:42 by fifrandr          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:22 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)(s1 + i)) != (*(unsigned char *)(s2 + i)))
			return ((*(unsigned char *)(s1 + i)) - (*(unsigned char *)
					(s2 + i)));
		i++;
	}
	return (0);
}
