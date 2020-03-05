/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_corner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 17:54:10 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_last_corner_start(t_map **map)
{
	int	h;
	int	w;

	h = 0;
	while (h < (*map)->map_height)
	{
		w = 0;
		while (w < (*map)->map_width)
		{
			if (ENEMY == (*map)->map[h][w])
				ft_set_last_corner(map, h, w);
			w++;
		}
		h++;
	}
}

void	ft_get_opposite_corner(t_map **map)
{
	int	h;
	int	w;

	h = 0;
	while (h < (*map)->map_height)
	{
		w = 0;
		while (w < (*map)->map_width)
		{
			if (PLAYER == (*map)->map[h][w])
				ft_set_opposite_corner(map, h, w);
			w++;
		}
		h++;
	}
	(*map)->opposite_reach = 0;
}

void	ft_get_last_corner(t_map **map)
{
	int	h;
	int	w;

	h = 0;
	while (h < (*map)->map_height)
	{
		w = 0;
		while (w < (*map)->map_width)
		{
			if (LAST == (*map)->map[h][w])
				ft_set_last_corner(map, h, w);
			w++;
		}
		h++;
	}
	if (-1 == (*map)->last_corner[0])
		ft_get_last_corner_start(map);
}

void	ft_get_shape_corner(t_map **map)
{
	int	i;
	int	j;

	(*map)->shape_corner[0] = -1;
	(*map)->shape_corner[1] = -1;
	(*map)->shape_corner[2] = -1;
	(*map)->shape_corner[3] = -1;
	i = 0;
	while (i < (*map)->piece_height)
	{
		j = 0;
		while (j < (*map)->piece_width)
		{
			if ('*' == (*map)->piece[i][j])
				ft_set_shape_corner(map, i, j);
			j++;
		}
		i++;
	}
}
