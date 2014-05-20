/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/07 22:36:29 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/07 22:36:30 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		choose_color(t_env *e, t_maps mini)
{
	if (e->map[mini.i][mini.j] == '1')
		e->color = YELLOW;
	else if (e->map[mini.i][mini.j] == '2')
		e->color = FUSHIA;
	else if (e->map[mini.i][mini.j] == '3')
		e->color = GREEN;
	else if (e->map[mini.i][mini.j] == '4' || (e->stage &&
			ft_strcmp(e->stage->str, "maps/poney") == 0 &&
			e->map[mini.i][mini.j] == '7'))
		e->color = BLUE;
	else if (e->map[mini.i][mini.j] == '5')
		e->color = 0xffffff;
	else
		e->color = BROWN;
}

void	ft_create_minimap(t_env *e)
{
	t_maps		mini;

	mini.a = (double)(LAR / 6) / (double)e->nb_c;
	mini.b = (double)(LON / 6) / (double)e->nb_l;
	mini.y = LON_M;
	mini.i = 0;
	draw_view(e, mini.a, mini.b);
	while (mini.i < e->nb_l)
	{
		mini.j = 0;
		mini.x = LAR_M;
		while (mini.j < e->nb_c)
		{
			if (e->map[mini.i][mini.j] != '0' && e->map[mini.i][mini.j] != '9')
			{
				choose_color(e, mini);
				draw_map(e, mini);
			}
			mini.x += mini.a;
			mini.j++;
		}
		mini.y += mini.b;
		mini.i++;
	}
	draw_player(e, LAR_M + (e->posx * mini.a), LON_M + (e->posy * mini.b));
}

void	ft_bezero(t_env *e)
{
	int		in;
	int		x;
	int		y;

	x = LAR_M;
	while (x < LAR)
	{
		y = LON_M;
		while (y < LON)
		{
			in = (e->bpp >> 3) * ((y * (e->size_line >> 2)) + x);
			e->str[in + 0] = 0x00;
			e->str[in + 1] = 0x00;
			e->str[in + 2] = 0x00;
			y++;
		}
		x++;
	}
}

void	ft_create_bigmap(t_env *e)
{
	t_maps		max;

	max.a = (double)LAR / (double)e->nb_c;
	max.b = (double)LON / (double)e->nb_l;
	max.y = max.i = 0;
	ft_bzero(e->str, LON * LAR * 4);
	while (max.i < e->nb_l)
	{
		max.j = max.x = 0;
		while (max.j < e->nb_c)
		{
			if (e->map[max.i][max.j] != '0')
			{
				choose_color(e, max);
				draw_map(e, max);
			}
			max.x += max.a;
			max.j++;
		}
		max.y += max.b;
		max.i++;
	}
	draw_player(e, (e->posx * max.a), (e->posy * max.b));
}
