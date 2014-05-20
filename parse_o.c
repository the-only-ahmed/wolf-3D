/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 01:08:18 by ael-kadh          #+#    #+#             */
/*   Updated: 2013/12/09 03:03:16 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		check_obj(t_env *e, char **tab, int i, int j)
{
	e->sprite[e->sprites_nb].x = j + 0.5;
	e->sprite[e->sprites_nb].y = i + 0.5;
	if (tab[i][j] == 'a')
		e->sprite[e->sprites_nb].texture = 0;
	else if (tab[i][j] == 'b')
		e->sprite[e->sprites_nb].texture = 1;
	else if (tab[i][j] == 'c')
		e->sprite[e->sprites_nb].texture = 2;
	else
		e->sprite[e->sprites_nb].texture = 3;
	e->sprites_nb++;
}

void		checks(t_env *e, char **tab, int i, int j)
{
	if (tab[i][j] == '5')
	{
		e->enter_x = j;
		e->enter_y = i;
	}
	else if (tab[i][j] == '6')
	{
		e->leave_x = j;
		e->leave_y = i;
	}
	else if (tab[i][j] == '9')
	{
		e->check_x = j;
		e->check_y = i;
	}
	else if (ft_isalpha(tab[i][j]))
		check_obj(e, tab, i, j);
}
