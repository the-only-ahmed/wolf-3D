/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 21:20:08 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/07 21:20:11 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_draw(t_env *data)
{
	data->y = data->drawstart;
	while (data->y < data->drawend)
	{
		data->in = (data->bpp >> 3) * (data->y * (data->size_line >> 2) + \
				(int)(data->x));
		data->str[data->in + 0] = data->color & 0xff;
		data->str[data->in + 1] = (data->color & 0xff00) >> 8;
		data->str[data->in + 2] = (data->color & 0xff0000) >> 16;
		data->y++;
	}
}

void	draw_map(t_env *e, t_maps map)
{
	int			in;
	double		y;
	double		x;

	x = map.x;
	while (x < map.x + map.a)
	{
		y = map.y;
		while (y < map.y + map.b)
		{
			in = (e->bpp >> 3) * (((int)y * (e->size_line >> 2)) + (int)x);
			e->str[in + 0] = e->color & 0xff;
			e->str[in + 1] = (e->color & 0xff00) >> 8;
			e->str[in + 2] = (e->color & 0xff0000) >> 16;
			y++;
		}
		x++;
	}
}

void	draw_player(t_env *e, double x, double y)
{
	int		in;
	double	a;
	double	b;
	int		tal;

	tal = (e->bol == 1)? 4 : 1;
	a = x - tal;
	while (a <= x + tal)
	{
		b = y - tal;
		while (b <= y + tal)
		{
			in = (e->bpp >> 3) * (((int)b * (e->size_line >> 2)) + (int)a);
			e->str[in + 0] = RED & 0xff;
			e->str[in + 1] = (RED & 0xff00) >> 8;
			e->str[in + 2] = (RED & 0xff0000) >> 16;
			b++;
		}
		a++;
	}
}

void	draw_view(t_env *e, double a, double b)
{
	t_cord		p1;
	t_cord		p2;
	double		r;

	ft_bezero(e);
	r = 20;
	while (r >= 0)
	{
		p1.x = (r * cos(e->angle - (M_PI / 6))) + LAR_M  + (e->posx * a);
		p2.x = (r * cos(e->angle + (M_PI / 6))) + LAR_M  + (e->posx * a);
		p1.y = (r * sin(e->angle - (M_PI / 6))) + LON_M + (e->posy * b);
		p2.y = (r * sin(e->angle + (M_PI / 6))) + LON_M + (e->posy * b);
		draw_seg(e, p1, p2);
		r--;
	}
}

void		draw_point(t_env *e, double x, double y)
{
	int		in;
	if (x < LAR_M || y < LON_M)
		return ;
	in = (e->bpp >> 3) * (((int)y * (e->size_line >> 2)) + (int)x);
	e->str[in + 0] = GREEN & 0xff;
	e->str[in + 1] = (GREEN & 0xff00) >> 8;
	e->str[in + 2] = (GREEN & 0xff0000) >> 16;
}
