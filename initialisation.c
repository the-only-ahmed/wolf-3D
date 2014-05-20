/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/10 12:54:15 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/10 12:54:22 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static char		**maps()
{
	char	**tab;

	tab = (char**)malloc(sizeof(char) * 150);
	tab[0] = ft_strdup("maps/map1.wolf3d");
	tab[1] = ft_strdup("maps/map2.wolf3d");
	tab[2] = ft_strdup("maps/map3.wolf3d");
	tab[3] = ft_strdup("maps/map4.wolf3d");
	tab[4] = ft_strdup("maps/map5.wolf3d");
	tab[5] = ft_strdup("maps/b");
	tab[6] = ft_strdup("maps/a");
	tab[7] = ft_strdup("maps/batman");
	tab[8] = ft_strdup("maps/poney");
	tab[9] = ft_strdup("maps/grimly");
	return (tab);
}

static char		**levels()
{
	char	**tab;

	tab = (char**)malloc(sizeof(char) * 200);
	tab[0] = ft_strdup("levels/level0.xpm");
	tab[1] = ft_strdup("levels/level1.xpm");
	tab[2] = ft_strdup("levels/level2.xpm");
	tab[3] = ft_strdup("levels/level3.xpm");
	tab[4] = ft_strdup("levels/level4.xpm");
	tab[5] = ft_strdup("levels/level5.xpm");
	tab[6] = ft_strdup("levels/level6.xpm");
	tab[7] = ft_strdup("levels/level7.xpm");
	tab[8] = ft_strdup("levels/level8.xpm");
	tab[9] = ft_strdup("levels/level9.xpm");
	return (tab);
}

static t_level		*mapping(char **map, char **lev, int i)
{
	t_level		*tmp;

	tmp = (t_level*)malloc(sizeof(t_level));
	tmp->str = ft_strdup(map[i]);
	tmp->lvl = ft_strdup(lev[i]);
	tmp->next = NULL;
	return (tmp);
}

t_level		*fill()
{
	t_level		*tmp;
	t_level		*back;
	char		**map;
	char		**lev;
	int			i;

	tmp = NULL;
	map = maps();
	lev = levels();
	i = 0;
	while (i < 10)
	{
		if (!tmp)
			tmp = back = mapping(map, lev, i);
		else
		{
			tmp->next = mapping(map, lev, i);
			tmp = tmp->next;
		}
		i++;
	}
	free(map);
	free(lev);
	return (back);
}
