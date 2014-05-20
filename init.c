/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 06:33:30 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/14 06:33:31 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		level_image(t_env *e)
{
	void	*xpm;
	int		lar;
	int		lon;

	ft_bzero(e->str, LON * LAR * 4);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	xpm = mlx_xpm_file_to_image (e->mlx, e->stage->lvl, &lar, &lon);
	mlx_put_image_to_window(e->mlx, e->win, xpm, LAR / 2 - lar / 2,
							LON / 2 - lon / 2);
	mlx_put_image_to_window(e->mlx, e->win, xpm, LAR / 2 - lar / 2,
							LON / 2 - lon / 2);
	sleep(1);
}

static void		cursor(t_env *e)
{
	Cursor	c;
	c = XCreateFontCursor(((t_xvar*)(e->mlx))->display, XC_crosshair);
	XDefineCursor(((t_xvar*)(e->mlx))->display\
			, ((t_xvar*)(e->mlx))->win_list->window, c);
}

static void		vars_init_loading(t_env *e)
{
	char	*line;
	int		fd;

	fd = open("save/pos.ahmed", O_RDONLY);
	get_next_line(fd, &line);
	e->dirx = ft_atoi_float(line);
	get_next_line(fd, &line);
	e->diry = ft_atoi_float(line);
	get_next_line(fd, &line);
	e->planex = ft_atoi_float(line);
	get_next_line(fd, &line);
	e->planey = ft_atoi_float(line);
	get_next_line(fd, &line);
	e->angle = ft_atoi_float(line);
	close(fd);
	free(line);
}

static void		vars_init(t_env *e)
{
	if (e->check_x != 500)
		vars_init_loading(e);
	else
	{
		e->dirx = -1;
		e->diry = 0;
		e->planex = 0;
		e->planey = 0.66;
		e->angle = deg_rad(180);
	}
	e->rotspeed = 0.1;
	e->draw = 1;
	e->tid = 0;
	e->bol = 0;
	e->sprite_Distance = (double*)malloc(sizeof(double) * e->sprites_nb);
}

void	init(t_env *e)
{
	void	*libre;

	cursor(e);
	e->map = ft_lecture(e->stage->str, e);
	libre = e->stage;
	if (e->check_x != 500)
	{
		e->posx = e->check_x;
		e->posy = e->check_y;
		delete_check(e);
	}
	else
	{
		e->posx = e->enter_x;
		e->posy = e->enter_y;
	}
	vars_init(e);
	fill_texture(e);
	fill_obj(e);
	level_image(e);
	e->stage = e->stage->next;
	free(libre);
}
