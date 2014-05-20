/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 05:17:55 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/14 05:17:56 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_expose_hook(t_env *e)
{
		e->draw = 1;
		return (0);
}

int		ft_main_hook(t_env *e)
{
	if (e->draw == 1 && e->bol != 1)
	{
		ft_intdraw(e);
		e->draw = 0;
	}
	return (0);
}

t_env	*get_instance()
{
	static t_env	*e = NULL;

	if (!e)
		e = (t_env*)malloc(sizeof(t_env));
	e->mlx = mlx_init();
	e->stage = fill();
	e->choix = 0;
	e->win = mlx_new_window(e->mlx, LAR, LON, "wolf 3D");
	if ((e->img = mlx_new_image(e->mlx, LAR, LON)) == NULL)
		exit(0);
	e->str = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line),
								&(e->endian));
	if (!(e->str))
		exit(0);
	menu(e);
	return (e);
}

void	chargement(t_env *e)
{
	void	*xpm;
	int		lar;
	int		lon;

	ft_bzero(e->str, LON * LAR * 4);
	xpm = mlx_xpm_file_to_image (e->mlx, "save/loading.xpm", &lar, &lon);
	mlx_put_image_to_window(e->mlx, e->win, xpm, LAR / 2 - lar / 2,
							LON / 2 - lon / 2);
	mlx_put_image_to_window(e->mlx, e->win, xpm, LAR / 2 - lar / 2,
							LON / 2 - lon / 2);
	sleep(1);
	init(e);
}
