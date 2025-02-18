/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fifrandr <fifrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 08:04:32 by fifrandr          #+#    #+#             */
/*   Updated: 2025/01/27 10:22:18 by fifrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_index(char c, char *str, size_t i)
{
	str[i] = c;
}

static int	ft_occ(int n)
{
	size_t	count;

	count = 1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	while (n <= -10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static size_t	ft_putnbr(int n, char *str, size_t i)
{
	if (n == -2147483648)
	{
		ft_index('-', str, i);
		i++;
		ft_index('2', str, i);
		i++;
		n = 147483648;
	}
	if (n < 0)
	{
		ft_index('-', str, i);
		i++;
		n *= -1;
	}
	if (n < 10)
	{
		ft_index(n + 48, str, i);
		i++;
	}
	else
	{
		i = ft_putnbr(n / 10, str, i);
		i = ft_putnbr(n % 10, str, i);
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	if (n >= 0)
		str = malloc(sizeof(char) * ft_occ(n) + 1);
	else
		str = malloc(sizeof(char) * ft_occ(n) + 2);
	if (!str)
		return (NULL);
	i = 0;
	if (n >= 0)
		str[ft_occ(n)] = '\0';
	else
		str[ft_occ(n) + 1] = '\0';
	ft_putnbr(n, str, i);
	return (str);
}
