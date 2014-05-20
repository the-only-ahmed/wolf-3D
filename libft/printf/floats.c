/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 00:31:24 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/19 21:08:41 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libftprintf.h"

static char	*ft_fill_number(double x, char *str, int i)
{
	int		a;
	int		j;
	int		rev;

	a = floor(x);
	if (a == 0)
	{
		str[i] = '0';
		i++;
	}
	else
	{
		rev = 0;
		while (a > 0)
		{
			rev *= 10;
			rev += a % 10;
			a /= 10;
		}
		while (rev > 0)
		{
			str[i] = (rev % 10) + '0';
			rev /= 10;
			i++;
		}
	}

	x -= floor(x);
	str[i] = '.';
	i++;
	j = 0;
	while (x > 0.0 && j < 6)
	{
		x *= 10.0;
		str[i] = floor(x) + '0';
		x -= floor(x);
		i++;
		j++;
	}
	if (str[i - 1] == '.' && j == 0)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_float(double x)
{
	int	i;
	char	*str;

	str = (char*)malloc(sizeof(char) * 100);
	i = 0;
	if (x < 0)
	{
		str[i] = '-';
		x = x * -1;
		i++;
	}
	str = ft_fill_number(x, str, i);
	return (str);
}

double		ft_atoi_float(const char *str)
{
	int			i;
	double		x;
	int			pt;
	double		a;
	int			neg;

	i = 0;
	x = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-' && str[i - 1] != '+')
	{
		neg = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
	{
		x *= 10;
		x += str[i] - 48;
		i++;
	}
	pt = a = 0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
		{
			a *= 10;
			a += str[i] - 48;
			i++;
			pt++;
		}
	}
	while (pt > 0)
	{
		a = a / 10;
		pt--;
	}
	x += a;
	x *= neg;
	return (x);
}
