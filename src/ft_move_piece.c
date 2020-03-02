/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:26:58 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 16:58:18 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_get_sum_max(t_map *map)
{
	int ret;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	while (i < map->piece_height)
	{
		j = 0;
		while (j < map->piece_width)
		{
			if ('*' == map->piece[i][j])
				ret++;
			j++;
		}
		i++;
	}
	ret *= ft_max(map->map_height, map->map_width);
	return (ret);
}

int		ft_get_sum(t_map *map, int h, int w)
{
	int ret;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	while (i < map->piece_height)
	{
		j = 0;
		while (j < map->piece_width)
		{
			if ('*' == map->piece[i][j])
			{
				if (map->map[h + i][w + j] >= 0)
					ret += map->map[h + i][w + j];
			}
			j++;
		}
		i++;
	}
	return (ret);
}

void	ft_get_piece_corner(t_map **map, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map)->piece_height)
	{
		j = 0;
		while (j < (*map)->piece_width)
		{
			if ('*' == (*map)->piece[i][j])
				ft_set_piece_corner(map, h + i, w + j);
			j++;
		}
		i++;
	}
}

int		ft_get_distance(t_map **map, int h, int w)
{
	int ret;

	ft_ini_piece_corner(map);
	ft_get_piece_corner(map, h, w);
	ret = ft_abs((*map)->last_corner[0] - (*map)->piece_corner[0]) +\
			ft_abs((*map)->last_corner[1] - (*map)->piece_corner[1]) +\
			ft_abs((*map)->last_corner[2] - (*map)->piece_corner[2]) +\
			ft_abs((*map)->last_corner[3] - (*map)->piece_corner[3]);
	return (ret);
}