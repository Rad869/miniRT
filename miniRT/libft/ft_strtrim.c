/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:40:14 by fifrandr          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:56 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_est_dans(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	debut;
	size_t	fin;

	debut = 0;
	while (s1[debut] && ft_char_est_dans(s1[debut], set))
		debut++;
	fin = ft_strlen(s1);
	while (fin > debut && ft_char_est_dans(s1[fin - 1], set))
		fin--;
	str = (char *)malloc(sizeof(*s1) * (fin - debut + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (debut < fin)
		str[i++] = s1[debut++];
	str[i] = '\0';
	return (str);
}
