/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 01:08:18 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/09 03:03:16 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		line_nb(char *file, int *x)
{
	int		fd;
	int		i;
	char	*str;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while (get_next_line(fd, &str) > 0)
	{
		*x = ft_strlen(str);
		i++;
	}
	if (close(fd) == -1)
		return (-1);
	return (i);
}

static char		**remplir(int fd, char **tab, t_env *e)
{
	int			i;
	int			j;
	char		*str;

	i = 0;
	e->check_x = 500;
	e->check_y = 0;
	while (i < e->nb_l)
	{
		j = 0;
		get_next_line(fd, &str);
		tab[i] = ft_strdup(str);
		while (j < e->nb_c)
		{
			checks(e, tab, i, j);
			j++;
		}
		i++;
	}
	return (tab);
}

char		**ft_lecture(char *file, t_env *e)
{
	int		fd;
	int		x;
	char	**tab;

	e->sprites_nb = 0;
	e->nb_l = line_nb(file, &x);
	if (e->nb_l == -1)
		return (NULL);
	e->nb_c = x;
	tab = (char**)malloc(sizeof(char) * (e->nb_l * e->nb_c));
	fd = open(file, O_RDONLY);
	tab = remplir(fd, tab, e);
	if (close(fd) == -1)
		return (NULL);
	return (tab);
}
