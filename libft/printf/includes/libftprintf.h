/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 16:41:40 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/11 04:33:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define SYM_INT str[i + 1] == '#' || str[i + 1] == '-' ||\
			(str[i + 1] == '.' && (str[i + 2] == 'd' || str[i + 2] == 'i'))
# define SYMB_INT str[*i + 1] == 'd' || str[*i + 1] == 'i' ||\
			((str[*i + 1] == ' ' || str[*i + 1] == '+') &&\
			(str[*i + 2] == 'd' || str[*i + 2] == 'i'))
# define SYM_CHAR str[*i + 1] == 'c' || ((str[*i + 1] == ' ' ||\
			str[*i + 1] == '+' || str[*i + 1] == '.') && str[*i + 2] == 'c')

int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_putstr(char const *str);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
char	*ft_strdup(const char *str);
int		ft_point(char const *str, int *i, int x, char *c);
int		ft_putunsigned_int(unsigned int n, int base);
int		ft_putunsigned_long(void *p, int base);
int		ft_putunsigned_2long(unsigned long long n);
int		ft_printpointeur(void *p);
int		condition(const char *str, int *i, va_list ap);
int		ft_abs(int x);
int		ft_all(const char *str, int *i, va_list ap);
int		ft_isascii(int c);
int		ft_all_2(int *i, const char *str, int x, int next);
int		first_else(int x, int next, char str, char c);
int		second_else(int x, int next, char str, char c);

int		ft_cond_2(const char *str, int *i, va_list ap);
int		ft_cond_1(const char *str, int *i, va_list ap, int x);
int		ft_cond_1c(int length, const char *str, int *i, va_list ap);
int		ft_cond_3(const char *str, int *i, int x);
int		ft_cond_3c(const char *str, int *i, int x);
int		condition_2(const char *str, int *i, va_list ap);
int		condition_3(const char *str, int *i, va_list ap);
int		condition_4(const char *str, int *i, va_list ap);

char	*ft_itoa_float(double x);
double	ft_atoi_float(const char *str);

#endif /* LIBFTPRINTF_H */
