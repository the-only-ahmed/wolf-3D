/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 00:08:39 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/18 00:08:47 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fill_texture(t_env *e)
{
	int		lar;
	int		lon;

	e->text[0] = mlx_xpm_file_to_image (e->mlx, "pics/wood.xpm", &lar, &lon);
	e->text[1] = mlx_xpm_file_to_image (e->mlx, "pics/floor.xpm", &lar, &lon);
	e->text[2] = mlx_xpm_file_to_image (e->mlx, "pics/redbrick.xpm", &lar,
										&lon);
	e->text[3] = mlx_xpm_file_to_image (e->mlx, "pics/bat.xpm", &lar, &lon);
	e->text[4] = mlx_xpm_file_to_image (e->mlx, "pics/greystone.xpm", &lar,
										&lon);
	e->text[5] = mlx_xpm_file_to_image (e->mlx, "pics/door.xpm", &lar, &lon);
	e->text[6] = mlx_xpm_file_to_image (e->mlx, "pics/bat2.xpm", &lar, &lon);
	e->text[7] = mlx_xpm_file_to_image (e->mlx, "pics/bat_enter.xpm", &lar,
										&lon);
	e->text[8] = mlx_xpm_file_to_image (e->mlx, "pics/final.xpm", &lar, &lon);
	e->text[9] = mlx_xpm_file_to_image (e->mlx, "pics/joker.xpm", &lar, &lon);
	e->text[10] = mlx_xpm_file_to_image (e->mlx, "pics/sand.xpm", &lar, &lon);
	e->text[11] = mlx_xpm_file_to_image (e->mlx, "pics/night.xpm", &lar, &lon);
	e->text[12] = mlx_xpm_file_to_image (e->mlx, "pics/day.xpm", &lar, &lon);
	e->text[13] = mlx_xpm_file_to_image (e->mlx, "pics/sand2.xpm", &lar, &lon);
	e->text[14] = mlx_xpm_file_to_image (e->mlx, "pics/grace.xpm", &lar, &lon);
}

void	fill_obj(t_env *e)
{
	int		lar;
	int		lon;

	e->obj[0] = mlx_xpm_file_to_image (e->mlx, "pics/barrel.xpm", &lar, &lon);
	e->obj[1] = mlx_xpm_file_to_image (e->mlx, "pics/pillar.xpm", &lar, &lon);
	e->obj[2] = mlx_xpm_file_to_image (e->mlx, "pics/greenlight.xpm", \
										&lar, &lon);
	e->obj[3] = mlx_xpm_file_to_image (e->mlx, "pics/monster.xpm", &lar, &lon);
}
