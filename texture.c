/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 06:09:34 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/11 06:09:43 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_gettextx(t_env *e)
{
	if (e->side == 1)
		e->wallx = e->rayposx + ((e->mapy - e->rayposy + (1 - \
						e->stepy) / 2) / e->raydiry) * e->raydirx;
	else
		e->wallx = e->rayposy + ((e->mapx - e->rayposx + (1 - \
						e->stepx) / 2) / e->raydirx) * e->raydiry;
	e->wallx -= floor((e->wallx));
	e->textx = (int)(e->wallx * (double)(e->text[e->tid]->width));
	if (e->side == 0 && e->raydirx > 0)
		e->textx = e->text[e->tid]->width - e->textx - 1;
	else if (e->side == 1 && e->raydiry < 0)
		e->textx = e->text[e->tid]->width - e->textx - 1;
	e->textx *= 4;
}

void		ft_settext(t_env *e, double y)
{
	e->in = (int)((e->bpp >> 3) * ((ceil(e->y) * \
					(e->size_line >> 2)) + (int)(e->x)));
	e->str[e->in + 0] = \
			e->text[e->tid]->data[(e->text[e->tid]->bpp >> 3) * \
			((int)(y) * e->text[e->tid]->size_line >> 2) + \
			e->textx + 0];
	e->str[e->in + 1] = \
			e->text[e->tid]->data[(e->text[e->tid]->bpp >> 3) * \
			((int)(y) * e->text[e->tid]->size_line >> 2) + \
			e->textx + 1];
	e->str[e->in + 2] = \
			e->text[e->tid]->data[(e->text[e->tid]->bpp >> 3) * \
			((int)(y) * e->text[e->tid]->size_line >> 2) + \
			e->textx + 2];
}

void		ft_drawtext(t_env *e)
{
	double		y;
	double		step;
	double		lheight;


	ft_gettextx(e);
	e->y = (double)(e->drawstart);
	lheight = ABS((double)LON / e->perpwalldist);
	y = (lheight / 2.0) - (double)LON / 2.0;
	step = (double)(e->text[e->tid]->height) / lheight;
	if (y <= 0)
		y = 0;
	else
		y *= step;
	while (e->y < e->drawend)
	{
		ft_settext(e, y);
		y += step;
		e->y++;
	}
}

int		map_text(t_env *e)
{
	if (e->stage && ft_strcmp(e->stage->str, "maps/poney") == 0)
	{
		if (e->map[e->mapy][e->mapx] == '6')
			return (9);
		else if (e->map[e->mapy][e->mapx] == '5')
			return (7);
	}
	if (!e->stage)
		if (e->map[e->mapy][e->mapx] == '6')
			return (8);
	return (e->map[e->mapy][e->mapx] - '1');
}
