/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:26:58 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 16:02:39 by rgero            ###   ########.fr       */
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


int		ft_check(t_map *map, int h, int w)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	while (i < map->piece_height)
	{
		j = 0;
		while (j < map->piece_width)
		{
			if (PLAYER == map->map[h + i][w + j] && '*' == map->piece[i][j])
				ret++;
			if (ENEMY == map->map[h + i][w + j] && '*' == map->piece[i][j])
				return (0);
			j++;
		}
		if (ret > 1)
			return (0);
		i++;
	}
	return (ret);
}

void	ft_set_piece(t_map **map, int *control, int h, int w)
{
	(*map)->piece_set = 1;
	(*map)->piece_min_summa = control[0];
	(*map)->piece_min_distance = control[1];
	(*map)->piece_h = h;
	(*map)->piece_w = w;
}

int		ft_put_piece(t_map **map, int h, int w)
{
	int	control[2];

	(*map)->piece_min_summa = ft_get_sum_max(*map);
	(*map)->piece_min_distance = 4 * ft_max((*map)->map_height, (*map)->map_width);
	h = 0;
	while (h + (*map)->piece_height <= (*map)->map_height)
	{
		w = 0;
		while (w + (*map)->piece_width <= (*map)->map_width)
		{
			if (ft_check(*map, h, w))
			{
				control[0] = ft_get_sum(*map, h, w);
				control[1] = ft_get_distance(map, h, w);
				if (control[0] <= (*map)->piece_min_summa && 
					control[1] <= (*map)->piece_min_distance)
					ft_set_piece(map, control, h, w);
			}
			w++;
		}
		h++;
	}
	ft_printf("%d %d\n", (*map)->piece_h, (*map)->piece_w);
	ft_del_piece(*map);
	if (0 == (*map)->piece_set)
		return (-1);
	return (0);
}
