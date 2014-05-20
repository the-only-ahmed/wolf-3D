/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 06:09:34 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/11 06:09:43 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ft_putctoimg(t_env *data, int y, int x, int c)
{
	int		*tmp;
	tmp = (int*)(data->str + (data->img->width * y * (data->bpp >> 3)) + \
			((data->bpp >> 3) * x));
	tmp[0] = c;
}

static int		*ft_order(t_env *e, int nb)
{
	int		i;
	int		*spriteOrder;

	i = 0;
	spriteOrder = (int*)malloc(sizeof(int) * nb);
	while (i < nb)
	{
		spriteOrder[i] = i;
		e->sprite_Distance[i] = ((e->posx - e->sprite[i].x)\
								*(e->posx - e->sprite[i].x)\
								+ (e->posy - e->sprite[i].y)\
								* (e->posy - e->sprite[i].y));
		i++;
	}
	combSort(spriteOrder, e->sprite_Distance, nb);
	return (spriteOrder);
}

static void		sprite_init(t_env *e, int *spriteOrder, int i)
{
	e->spriteX = e->sprite[spriteOrder[i]].x - e->posx;
	e->spriteY = e->sprite[spriteOrder[i]].y - e->posy;
	e->invDet = 1.0 / (e->planex * e->diry - e->dirx * e->planey);
	e->transformX = e->invDet * (e->diry * e->spriteX - e->dirx * e->spriteY);
	e->transformY = e->invDet * (-(e->planey) * e->spriteX + e->planex\
					* e->spriteY);
	e->spriteScreenX = (int)((LAR / 2) * (1 + e->transformX / e->transformY));
	e->spriteHeight = abs((int)(LON / (e->transformY)));
	e->drawStartY = -(e->spriteHeight) / 2 + LON / 2;
	if(e->drawStartY < 0)
		e->drawStartY = 0;
	e->drawEndY = e->spriteHeight / 2 + LON / 2;
	if(e->drawEndY >= LON)
		e->drawEndY = LON - 1;
	e->spriteWidth = abs((int)(LON / (e->transformY)));
	e->drawStartX = -(e->spriteWidth) / 2 + e->spriteScreenX;
	if(e->drawStartX < 0)
		e->drawStartX = 0;
	e->drawEndX = e->spriteWidth / 2 + e->spriteScreenX;
	if(e->drawEndX >= LAR)
		e->drawEndX = LAR - 1;
}

static void		stripe_draw(t_env *e, int *spriteOrder, int i, int stripe)
{
	int		*tmp;
	int		d;
	t_img	*rac;

	rac = e->obj[e->sprite[spriteOrder[i]].texture];
	e->y = e->drawStartY;
	while (e->y < e->drawEndY)
	{
		d = (e->y) * 256 - LON * 128 + e->spriteHeight * 128;
		e->texty = ((d * rac->height) / e->spriteHeight) / 256;
		tmp = (int*)(rac->data + rac->width * (e->texty * (rac->bpp >> 3))\
				+ (e->textx * (e->bpp >> 3)));
		if ((tmp[0] >> 24) != -1)
			ft_putctoimg(e, e->y, stripe, tmp[0]);
		e->y++;
	}
}

void			sprite_casting(t_env *e, int nb)
{
	int		i;
	int		stripe;
	int		*spriteOrder;

	spriteOrder = ft_order(e, nb);
	i = 0;
	while (i < nb)
	{
		sprite_init(e, spriteOrder, i);
		stripe = e->drawStartX;
		while (stripe < e->drawEndX)
		{
			e->textx = (int)(256 * (stripe - (e->spriteScreenX\
						- e->spriteWidth / 2))\
						* e->obj[e->sprite[spriteOrder[i]].texture]->width\
						/ e->spriteHeight) / 256;
			if(e->transformY > 0 && stripe > 0 && stripe < LAR && e->transformY\
				< e->Zbuffer[stripe])
				stripe_draw(e, spriteOrder, i, stripe);
			stripe++;
		}
		i++;
	}
}
