/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 12:52:55 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/10 12:53:06 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_draw_weapon(t_env *e, int x, int y, t_img *xpm)
{
	int		mul;
	int		i;

	mul = y;
	i = 0;
	while (mul < y + (xpm->width * xpm->height * (xpm->bpp >> 3)) / \
			xpm->size_line)
	{
		if (xpm->data[i + 3] != -1)
		{
			e->str[(mul * e->size_line) + (x * e->bpp >> 3) + \
					(i % xpm->size_line)] = xpm->data[i];
			e->str[(mul * e->size_line) + (x * e->bpp >> 3) + \
					(i % xpm->size_line) + 1] = xpm->data[i + 1];
			e->str[(mul * e->size_line) + (x * e->bpp >> 3) + \
					(i % xpm->size_line) + 2] = xpm->data[i + 2];
		}
		i += 4;
		if (!(i % xpm->size_line))
			mul++;
	}
}

void	ft_draw_thing(t_env *e, int x)
{
	int		lon;
	int		lar;
	t_img	*xpm;

	if (x)
	{
		xpm = mlx_xpm_file_to_image (e->mlx, "pics/gun.xpm", &lar, &lon);
		ft_draw_weapon(e, LAR + 650, LON - 600, xpm);
	}
	else
	{
		xpm = mlx_xpm_file_to_image (e->mlx, "pics/feu.xpm", &lar, &lon);
		ft_draw_weapon(e, (LAR / 2) - 150, (LON / 2) + 200, xpm);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
}

int		ft_intdraw(t_env *e)
{
	int		lar;
	int		lon;
	void	*xpm;

	lar = LAR;
	lon = LON;
	raycasting(e);
	sprite_casting(e, e->sprites_nb);
	ft_draw_thing(e, 1);
	ft_create_minimap(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (LEAVE_0 || LEAVE_1 || LEAVE_2 || LEAVE_3 || LEAVE_4 || LEAVE_5 ||
			LEAVE_6)
	{
		if (!e->stage)
		{
			xpm = mlx_xpm_file_to_image (e->mlx, "levels/win.xpm", &lar, &lon);
			mlx_put_image_to_window(e->mlx, e->win, xpm, 0, 0);
			mlx_put_image_to_window(e->mlx, e->win, xpm, 0, 0);
			sleep(5);
			exit(0);
		}
		init(e);
	}
	return (0);
}
