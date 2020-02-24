/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:56:41 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 15:07:13 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_distance(t_map *map, int h, int w)
{
	int	i;

	i = map->plateau->hmap[h][w] + 1;
	f (h > 0)
}

void ft_heat(t_map *map)
{
	int	h;
	int	w;
	int	max;
	int	i;

	max = (map->plateau->height > map->plateau->width\
		? map->plateau->height : map->plateau->width);
	i = 0;
	while (i < max)
	{
		h = 0;
		while (h < map->plateau->height)
		{
			w = 0;
			while (w < map->plateau->width)
			{
				if (map->plateau->hmap[h][w] == i)
					ft_put_distance(map, h, w);
				w++;
			}
			h++;
		}
		i++;
	}
}
