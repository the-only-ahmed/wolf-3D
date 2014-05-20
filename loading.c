/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 00:31:15 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/11 00:31:16 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_level		*loading(t_env *e)
{
	char	*line;
	int		fd;

	fd = open("save/save.ahmed", O_RDONLY);
	if (fd == -1)
		return (e->stage);
	get_next_line(fd, &line);
	while (e->stage)
	{
		if (ft_strcmp(e->stage->next->str, line) == 0)
		{
			e->stage->str = ft_strdup("save/map.ahmed");
			close(fd);
			return (e->stage);
		}
		e->stage = e->stage->next;
	}
	return (e->stage);
}

void	delete_check(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->nb_l)
	{
		j = 0;
		while (j < e->nb_c)
		{
			if (e->map[i][j] == '9')
				e->map[i][j] = '0';
			j++;
		}
		i++;
	}
}

t_level		*charge(t_env *e)
{
	char	*line;
	int		fd;

	fd = open("save/choix.ahmed", O_RDONLY);
	get_next_line(fd, &line);
	while (e->stage)
	{
		if (ft_strcmp(e->stage->str, line) == 0)
		{
			close(fd);
			return (e->stage);
		}
		e->stage = e->stage->next;
	}
	return (e->stage);
}
