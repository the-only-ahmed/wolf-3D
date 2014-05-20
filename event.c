/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 21:20:16 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/07 21:20:18 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		key_left(t_env *e)
{
	double		oldirx;
	double		olplanex;

	oldirx = e->dirx;
	e->dirx = e->dirx * cos(e->rotspeed) - e->diry * sin(e->rotspeed);
	e->diry = oldirx * sin(e->rotspeed) + e->diry * cos(e->rotspeed);
	olplanex = e->planex;
	e->planex = e->planex * cos(e->rotspeed) - e->planey * sin(e->rotspeed);
	e->planey = olplanex * sin(e->rotspeed) + e->planey * cos(e->rotspeed);
	e->angle += e->rotspeed;
}

static void		key_right(t_env *e)
{
	double		oldirx;
	double		olplanex;

	oldirx = e->dirx;
	e->dirx = e->dirx * cos(-(e->rotspeed)) - e->diry * sin(-(e->rotspeed));
	e->diry = oldirx * sin(-(e->rotspeed)) + e->diry * cos(-(e->rotspeed));
	olplanex = e->planex;
	e->planex = e->planex * cos(-(e->rotspeed)) - e->planey\
				* sin(-(e->rotspeed));
	e->planey = olplanex * sin(-(e->rotspeed)) + e->planey\
				* cos(-(e->rotspeed));
	e->angle -= e->rotspeed;
}

static void		key_up_down(t_env *e, int keycode)
{
	if ((keycode == UP || keycode == 119) && e->bol != 1)
	{
		if (e->map[(int)e->posy][(int)(e->posx + e->dirx\
			* (MOVE_SPEED + 0.3))] == '0')
			e->posx += e->dirx * MOVE_SPEED;
		if (e->map[(int)(e->posy + e->diry\
			* (MOVE_SPEED + 0.3))][(int)e->posx] == '0')
			e->posy += e->diry * MOVE_SPEED;
	}
	if ((keycode == DOWN || keycode == 115) && e->bol != 1)
	{
		if (e->map[(int)e->posy][(int)(e->posx - e->dirx\
			* (MOVE_SPEED + 0.3))] == '0')
			e->posx -= e->dirx * MOVE_SPEED;
		if (e->map[(int)(e->posy - e->diry\
			* (MOVE_SPEED + 0.3))][(int)e->posx] == '0')
			e->posy -= e->diry * MOVE_SPEED;
	}
}

int		key_hook(int keycode, t_env *e)
{
	if ((keycode == LEFT || keycode == 97) && e->bol != 1)
		key_left(e);
	if ((keycode == RIGHT || keycode == 100) && e->bol != 1)
		key_right(e);
	key_up_down(e, keycode);
	if (keycode == 32 || e->bol == 1)
	{
		ft_create_bigmap(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		e->bol = 1;
		if (keycode == 'q')
			e->bol = 0;
	}
	if (keycode == 'h')
		sauvegarde(e);
	if (keycode == 65307)
	{
		ft_printf("You're a LOOOOOOOSER.\n");
		exit (0);
	}
	e->draw = 1;
	return (0);
}
