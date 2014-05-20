/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 23:55:28 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/30 23:56:38 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_env	*e;
	static int	i = 0;

	(void)av;
	if (!i)
	{
		e = get_instance();
		i++;
	}
	if (ac == 3)
		e->stage = loading(e);
	else if (ac == 4)
		e->stage = charge(e);
	chargement(e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, mouse_hook, e);
	mlx_hook(e->win, 2, 3, key_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_mouse_hook(e->win, mouse_click_hook, e);
	mlx_loop_hook(e->mlx, ft_main_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
