/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 02:13:15 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/08 02:13:17 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		seg_1(t_env *e, t_cord *p1, t_cord *p2, t_seg *tmp)
{
	if(tmp->dx >= tmp->dy && tmp->dx != 0 && tmp->dy != 0)
	{
		if(p1->x > p2->x)
		{
			tmp->temp = p1->x;
			p1->x = p2->x;
			p2->x = tmp->temp;
			tmp->temp = p1->y;
			p1->y = p2->y;
			p2->y = tmp->temp;
		}
		tmp->a = ((float)(p2->y - p1->y) / (p2->x - p1->x));
		tmp->x = 0;
		while (tmp->x < tmp->dx + 1)
		{
			draw_point(e, tmp->x + p1->x, p1->y + (tmp->x * tmp->a) +\
						tmp->cste);
			tmp->x++;
		}
	}
}

static void		seg_2(t_env *e, t_cord *p1, t_cord *p2, t_seg *tmp)
{
	if(tmp->dx < tmp->dy && tmp->dx != 0 && tmp->dy != 0)
	{
		if(p1->y > p2->y)
		{
			tmp->temp = p1->y;
			p1->y = p2->y;
			p2->y = tmp->temp;
			tmp->temp = p1->x;
			p1->x = p2->x;
			p2->x = tmp->temp;
		}
		tmp->a = ((float)(p2->x-p1->x) / (p2->y-p1->y));
		tmp->y = 0;
		while (tmp->y < tmp->dy + 1)
		{
			draw_point(e, p1->x + (tmp->y * tmp->a) + tmp->cste, \
						tmp->y + p1->y);
			tmp->y++;
		}
	}
}

static void		seg_3(t_env *e, t_cord *p1, t_cord *p2, t_seg *tmp)
{
	if(tmp->dx == 0)
	{
		if(p1->y > p2->y)
		{
			tmp->temp = p1->y;
			p1->y = p2->y;
			p2->y = tmp->temp;
		}
		tmp->y = p1->y;
		while (tmp->y < p2->y + 1)
		{
			draw_point(e, p1->x, tmp->y);
			tmp->y++;
		}
	}
}

static void		seg_4(t_env *e, t_cord *p1, t_cord *p2, t_seg *tmp)
{
	if(tmp->dy == 0)
	{
		if(p1->x > p2->x)
		{
			tmp->temp = p1->x;
			p1->x = p2->x;
			p2->x = tmp->temp;
		}
		tmp->x = p1->x;
		while (tmp->x < p2->x + 1)
		{
			draw_point(e, tmp->x, p1->y);
			tmp->x++;
		}
	}
}

void	draw_seg(t_env *e, t_cord p1, t_cord p2)
{
	t_seg	tmp;

	tmp.a = 0;
	tmp.temp = 0;
	tmp.cste = 0;
	tmp.dx = abs(p2.x - p1.x);
	tmp.dy = abs(p2.y - p1.y);

	seg_1(e, &p1, &p2, &tmp);
	seg_2(e, &p1, &p2, &tmp);
	seg_3(e, &p1, &p2, &tmp);
	seg_4(e, &p1, &p2, &tmp);
}
