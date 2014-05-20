/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 00:32:24 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/11 00:32:25 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ecrire(int fd[2], t_env *e)
{
	ft_putendl_fd(e->stage->str, fd[0]);
	ft_putendl_fd(ft_itoa_float(e->dirx), fd[1]);
	ft_putendl_fd(ft_itoa_float(e->diry), fd[1]);
	ft_putendl_fd(ft_itoa_float(e->planex), fd[1]);
	ft_putendl_fd(ft_itoa_float(e->planey), fd[1]);
	ft_putendl_fd(ft_itoa_float(e->angle), fd[1]);
	check_point(e);
}

void		sauvegarde(t_env *e)
{
	void	*xpm;
	int		lar;
	int		lon;
	int		fd[2];

	ft_bzero(e->str, LON * LAR * 4);
	xpm = mlx_xpm_file_to_image (e->mlx, "save/save.xpm", &lar, &lon);
	mlx_put_image_to_window\
	(e->mlx, e->win, xpm, LAR / 2 - lar / 2, LON / 2 - lon / 2);
	mlx_put_image_to_window\
	(e->mlx, e->win, xpm, LAR / 2 - lar / 2, LON / 2 - lon / 2);
	sleep(1);
	fd[0] = open("save/save.ahmed", O_RDWR | O_CREAT | O_TRUNC, 0644);
	fd[1] = open("save/pos.ahmed", O_RDWR | O_CREAT | O_TRUNC, 0644);
	ecrire(fd, e);
	close(fd[0]);
	close(fd[1]);
}

void	check_point(t_env *e)
{
	int		i;
	int		j;
	int		fd;

	fd = open("save/map.ahmed", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU |
								S_IRGRP | S_IROTH);
	i = 0;
	while (i < e->nb_l)
	{
		j = 0;
		while (j < e->nb_c)
		{
			if (ceil(e->posx) == j && ceil(e->posy) == i)
				ft_putchar_fd('9', fd);
			else
				ft_putchar_fd(e->map[i][j], fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}
