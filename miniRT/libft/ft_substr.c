/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:05:05 by fifrandr          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:58 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*blank;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	blank = (char *)ft_calloc((len + 1), sizeof(char));
	if (!blank)
		return (NULL);
	while (i != len)
	{
		blank[i] = s[start + i];
		i++;
	}
	blank[len] = '\0';
	return (blank);
}
