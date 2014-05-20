/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 21:20:41 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/07 21:20:43 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ft_line(t_env *env)
{
	env->lineheight = ABS((int)(LON / env->perpwalldist));
	env->drawstart = -(env->lineheight) / 2 + LON / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + LON / 2;
	if (env->drawend >= LON)
		env->drawend = LON - 1;
	env->tid = map_text(env);
	ft_drawtext(env);
	flooring(env);
	env->Zbuffer[env->x] = env->perpwalldist;
}

void		ft_dda(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->ddistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->ddisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if ((env->mapy < env->nb_l / 2 || env->mapx < env->nb_c / 2)
			|| (env->mapy > 0 || env->mapx > 0))
			{
				if (HIT)
					env->hit = 1;
			}
	}
	if (env->side == 0)
		env->perpwalldist = fabs(PERP_NULL);
	else
		env->perpwalldist = fabs(PERP);
}

void		ft_init(t_env *env)
{
	env->camerax = 2 * (float)env->x / (double)LAR - 1;
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->ddistx = sqrt(1 + (env->raydiry * env->raydiry) / (env->raydirx *
						env->raydirx));
	env->ddisty = sqrt(1 + (env->raydirx * env->raydirx) / (env->raydiry *
						env->raydiry));
	env->hit = 0;
	if (env->raydirx < 0)
		env->stepx = -1;
	else
		env->stepx = 1;
	if (env->raydiry < 0)
		env->stepy = -1;
	else
		env->stepy = 1;
}

void		raycasting(t_env *env)
{
	env->x = 0;
	while (env->x < LAR)
	{
		ft_init(env);
		if (env->raydirx < 0)
			env->sidedistx = (env->rayposx - env->mapx) * env->ddistx;
		else
			env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->ddistx;
		if (env->raydiry < 0)
			env->sidedisty = (env->rayposy - env->mapy) * env->ddisty;
		else
			env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->ddisty;
		if ((env->mapy > env->nb_l || env->mapx > env->nb_c) || (env->mapy < 1
			|| env->mapx < 1))
			break ;
		ft_dda(env);
		ft_line(env);
		env->x++;
	}
}
