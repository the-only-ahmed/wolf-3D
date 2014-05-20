/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 12:49:07 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/11 04:45:46 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ap;

	i = 0;
	length = ft_strlen(str);
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (SYM_INT)
			{
				length--;
				i++;
			}
			length += condition(str, &i, ap);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (length);
}

int		condition(const char *str, int *i, va_list ap)
{
	int		length;
	int		x;
	double	f;

	length = 0;
	if (str[*i + 1] >= 48 && str[*i + 1] <= 57)
	{
		x = *i + 1;
		while (str[x] >= 48 && str[x] <= 57)
			x++;
		length += ft_cond_1(str, i, ap, x);
	}
	else if (str[*i + 1] == '.' && str [*i + 2] >= 48 && str[*i + 2] <= 57)
		length += ft_cond_2(str, i, ap);
	else if (SYMB_INT)
	{
		x = va_arg(ap, int);
		length += ft_cond_3(str, i, x);
	}
	else if (str[*i + 1] == 'f')
	{
		f = va_arg(ap, double);
		length += ft_putstr(ft_itoa_float(f));
	}
	else
		length += condition_2(str, i, ap);
	return (length);
}
