/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 06:20:56 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/14 06:20:57 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		mouse_left(t_env *e, double a)
{
	double		oldirx;
	double		olplanex;

	oldirx = e->dirx;
	e->dirx = e->dirx * cos(a) - e->diry * sin(a);
	e->diry = oldirx * sin(a) + e->diry * cos(a);
	olplanex = e->planex;
	e->planex = e->planex * cos(a) - e->planey * sin(a);
	e->planey = olplanex * sin(a) + e->planey * cos(a);
	e->angle += e->rotspeed / 2;
}

static void		mouse_right(t_env *e, double a)
{
	double		oldirx;
	double		olplanex;

	oldirx = e->dirx;
	e->dirx = e->dirx * cos(-(a)) - e->diry * sin(-(a));
	e->diry = oldirx * sin(-(a)) + e->diry * cos(-(a));
	olplanex = e->planex;
	e->planex = e->planex * cos(-(a)) - e->planey * sin(-(a));
	e->planey = olplanex * sin(-(a)) + e->planey * cos(-(a));
	e->angle -= e->rotspeed / 2;
}

int			mouse_hook(int x, int y, t_env *e)
{
	int			difx;
	int			dify;
	double		a;

	difx = x - LAR / 2;
	dify = y - LON / 2;
	a = 0.05;
	if ((difx < 0) && e->bol != 1)
		mouse_left(e, a);
	else if ((difx > 0) && e->bol != 1)
		mouse_right(e, a);
	XWarpPointer(((t_xvar*)(e->mlx))->display, 0\
			, ((t_xvar*)(e->mlx))->win_list->window, 0, 0, LAR\
			, LON, LAR / 2, LON / 2);
	e->draw = 1;
	return (0);
}

int			mouse_click_hook(int button, int x, int y, t_env *env)
{
	x = y;
	if ((button == 1) && env->bol != 1)
	{
		ft_draw_thing(env, 0);
		env->x = LAR / 2;
		ft_init(env);
		if (env->raydirx < 0)
			env->sidedistx = (env->rayposx - env->mapx) * env->ddistx;
		else
			env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->ddistx;
		if (env->raydiry < 0)
			env->sidedisty = (env->rayposy - env->mapy) * env->ddisty;
		else
			env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->ddisty;
		ft_dda(env);
		if (env->map[env->mapy][env->mapx] != '1' &&
			env->map[env->mapy][env->mapx] != '5' &&
			env->map[env->mapy][env->mapx] != '6'
			&& env->map[env->mapy][env->mapx] != '0' &&
			(!env->stage ||
			(env->stage && ft_strcmp(env->stage->str, "maps/poney"))))
				env->map[env->mapy][env->mapx] = '0';
	}
	env->draw = 1;
	return (0);
}
