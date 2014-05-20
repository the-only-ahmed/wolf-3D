/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 23:50:05 by ael-kadh          #+#    #+#             */
/*   Updated: 2014/01/17 23:50:12 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		swapping(int *order, double *dist, int amount, int gap)
{
	int		i;
	int		j;
	int		tmp;
	double	temp;
	int		swapped;

	i = 0;
	swapped = 0;
	while (i < amount - gap)
	{
		j = i + gap;
		if (dist[i] < dist[j])
		{
			temp = dist[i];
			dist[i] = dist[j];
			dist[j] = temp;
			tmp = order[i];
			order[i] = order[j];
			order[j] = tmp;
			swapped = 1;
		}
		i++;
	}
	return (swapped);
}

void		combSort(int *order, double *dist, int amount)
{
	int		gap;
	int		swapped;

	gap = amount;
	swapped = 0;
	while(gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if(gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = swapping(order, dist, amount, gap);
	}
}
