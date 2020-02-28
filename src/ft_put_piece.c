/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:26:58 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 14:53:56 by rgero            ###   ########.fr       */
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
	ret *= (map->map_height > map->map_width\
		? map->map_height : map->map_width);
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
				ret += map->map[h + i][w + j];
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
				ft_set_corner(&((*map)->piece_corner), h + i, w + j);
			j++;
		}
		i++;
	}
}

int		ft_get_distance(t_map **map, int h, int w)
{
	int ret;

	ft_ini_corner(&((*map)->piece_corner));
	ft_get_pice_corner(map, h, w);
	ret = ABS((*map)->last_corner[0] - (*map)->piece_corner[0]) +\
			ABS((*map)->last_corner[1] - (*map)->piece_corner[1]) +\
			ABS((*map)->last_corner[2] - (*map)->piece_corner[2]) +\
			ABS((*map)->last_corner[3] - (*map)->piece_corner[3]);
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

void	ft_set_piece(t_map **map, int sum, int h, int w)
{
	(*map)->piece_set = 1;
	(*map)->piece_min_summa = sum;
	(*map)->piece_min_distance = sum;

	(*map)->piece_h = h;
	(*map)->piece_w = w;
}

int		ft_put_piece(t_map **map, int h, int w)
{
	int	control[2];

	(*map)->piece_min_summa = ft_get_sum_max(*map);
	h = 0;
	while (h + (*map)->piece_height <= (*map)->map_height)
	{
		w = 0;
		while (w + (*map)->piece_width <= (*map)->map_width)
		{
			if (ft_check(*map, h, w))
			{
				sum = ft_get_sum(*map, h, w);
				distance = ft_get_distance(*map, h, w);
				if (sum <= (*map)->piece_min)
					ft_set_piece(map, sum, h, w);
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
