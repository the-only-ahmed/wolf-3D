/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 06:40:17 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/10 06:40:20 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	menu(t_env *e)
{
	void	*xpm;
	int		lar;
	int		lon;
	static int i = 0;

	if (i)
		return ;
	i++;
	xpm = mlx_xpm_file_to_image (e->mlx, "levels/menu.xpm", &lar, &lon);
	mlx_put_image_to_window(e->mlx, e->win, xpm, 0, 0);
	mlx_put_image_to_window(e->mlx, e->win, xpm, 0, 0);

	mlx_mouse_hook(e->win, mouse_menu_hook, e);
	mlx_loop(e->mlx);
}

int		mouse_menu_hook(int button, int x, int y, t_env *e)
{
	if (button == 1 && !e->choix)
	{
		if (x >= 305 && x <= 770 && y >= 340 && y <= 415)
			main(1, NULL);
		else if (x >= 425 && x <= 640 && y >= 870 && y <= 935)
			exit(0);
		else if (x >= 280 && x <= 780 && y >= 465 && y <= 565)
			main(3, NULL);
		else if (x >= 330 && x <= 715 && y >= 610 && y <= 675)
			choice(e);
	}
	else if (e->choix)
		i9tira7(e, x, y, button);
	return (0);
}

void	choice(t_env *e)
{
	t_level		*tmp;
	int			x;
	int			y;
	char		*str;

	tmp = e->stage;
	ft_bzero(e->str, LON * LAR * 4);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	y = 200;
	while (tmp)
	{
		str = ft_strrchr(tmp->str, '/') + 1;
		x = LAR / 2 - ft_strlen(str);
		mlx_string_put(e->mlx, e->win, x, y, 0xFFFFFF, str);
		tmp = tmp->next;
		y += 100;
	}
	e->choix = 1;
	menu(e);
}

static int	i9tira7_b(int y)
{
	if (y >= 190 && y <= 205)
		return (0);
	else if (y >= 290 && y <= 305)
		return (1);
	else if (y >= 390 && y <= 405)
		return (2);
	else if (y >= 490 && y <= 505)
		return (3);
	else if (y >= 590 && y <= 605)
		return (4);
	else if (y >= 690 && y <= 705)
		return (5);
	else if (y >= 790 && y <= 805)
		return (6);
	else if (y >= 890 && y <= 905)
		return (7);
	else if (y >= 990 && y <= 1005)
		return (8);
	else if (y >= 1090 && y <= 1105)
		return (9);
	else
		return (-1);
}

void		i9tira7(t_env *e, int x, int y, int button)
{
	int		n;
	int		fd;

	n = -1;
	if (button == 1)
	{
		if (x >= 740 && x <= 805)
			n = i9tira7_b(y);
	}
	if (n != -1)
	{
		while (n > 0)
		{
			e->stage = e->stage->next;
			n--;
		}
		fd = open("save/choix.ahmed", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU |
										S_IRGRP | S_IROTH);
		ft_putendl_fd(e->stage->str, fd);
		close(fd);
		main(4, NULL);
	}
}
