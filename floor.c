/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 19:54:59 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/12 19:55:10 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		the_dessin(t_env *e)
{
	if (e->stage && ft_strcmp(e->stage->str, "maps/poney") == 0)
		e->tid = 6;
	else if (!e->stage || ft_strcmp(e->stage->str, "maps/grimly") == 0)
		e->tid = 13;
	else if (e->stage && ft_strcmp(e->stage->str, "maps/batman") == 0)
		e->tid = 14;
	else
		e->tid = 10;

	if (e->stage && ft_strcmp(e->stage->str, "maps/poney") == 0)
		e->tis = 11;
	else
		e->tis = 12;
}

static void		setting_cf_text(t_env *e)
{
	t_resume	tmp;

	tmp.distWall = e->perpwalldist;
	tmp.distPlayer = 0.0;
	e->y = e->drawend + 1;
	the_dessin(e);
	while (e->y < LON)
	{
		tmp.currentDist = LON / (2.0 * e->y - LON);
		tmp.weight = (tmp.currentDist - tmp.distPlayer)\
						/ (tmp.distWall - tmp.distPlayer);
		tmp.currentFloorX = tmp.weight * e->floorXWall\
							+ (1.0 - tmp.weight) * e->posx;
		tmp.currentFloorY = tmp.weight * e->floorYWall\
							+ (1.0 - tmp.weight) * e->posy;
		e->floorTexX = (int)(tmp.currentFloorX * e->text[e->tid]->width)\
							% e->text[e->tid]->width;
		e->floorTexY = (int)(tmp.currentFloorY * e->text[e->tid]->height)\
							% e->text[e->tid]->height;
		ft_draw_floor(e);
		ft_draw_ceil(e);
		e->y++;
	}
}

void		flooring(t_env *e)
{
	if(e->side == 0 && e->raydirx > 0)
	{
		e->floorXWall = e->mapx;
		e->floorYWall = e->mapy + e->wallx;
	}
	else if(e->side == 0 && e->raydirx < 0)
	{
		e->floorXWall = e->mapx + 1.0;
		e->floorYWall = e->mapy + e->wallx;
	}
	else if(e->side == 1 && e->raydiry > 0)
	{
		e->floorXWall = e->mapx + e->wallx;
		e->floorYWall = e->mapy;
	}
	else
	{
		e->floorXWall = e->mapx + e->wallx;
		e->floorYWall = e->mapy + 1.0;
	}
	if (e->drawend < 0)
		e->drawend = LON;
	setting_cf_text(e);
}

void		ft_draw_floor(t_env *e)
{
	e->in = (int)((e->bpp >> 3) * (((e->y) * \
					(e->size_line >> 2)) + (int)(e->x)));
	e->str[e->in + 0] = e->text[e->tid]->data[e->text[e->tid]->width *\
						(e->floorTexY << 2) + (e->floorTexX << 2)];
	e->str[e->in + 1] = e->text[e->tid]->data[e->text[e->tid]->width *\
						(e->floorTexY << 2) + (e->floorTexX << 2) + 1];
	e->str[e->in + 2] = e->text[e->tid]->data[e->text[e->tid]->width *\
						(e->floorTexY << 2) + (e->floorTexX << 2) + 2];
}

void		ft_draw_ceil(t_env *e)
{
	e->in = (int)((e->bpp >> 3) * (((LON - e->y) * \
					(e->size_line >> 2)) + (int)(e->x)));
	e->str[e->in + 0] = e->text[e->tis]->data[e->text[e->tis]->width *\
						(e->floorTexY << 2) + (e->floorTexX << 2)];
	e->str[e->in + 1] = e->text[e->tis]->data[e->text[e->tis]->width *\
						(e->floorTexY << 2) + (e->floorTexX << 2) + 1];
	e->str[e->in + 2] = e->text[e->tis]->data[e->text[e->tis]->width *\
						(e->floorTexY << 2) + (e->floorTexX << 2) + 2];
}
