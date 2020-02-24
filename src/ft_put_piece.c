/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:26:58 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 17:07:34 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void		ft_put_piece(t_map *map)
{
	int	h;
	int	w;
	int	min;
	int	sum;

	min = 1000;
	h = 0;
	while (h + map->piece_height <= map->map_height)
	{
		w = 0;
		while (w + map->piece_width <= map->map_width)
		{
			if (ft_check(map, h, w))
			{
				sum = ft_get_sum(map, h, w);
				if (sum <= min)
				{
					min = sum;
					map->piece_h = h;
					map->piece_w = w;
				}
			}
			w++;
		}
		h++;
	}
	ft_printf("%d %d\n", map->piece_h, map->piece_w);
}

void	ft_del_piece(t_map *map)
{
	int i;

	i = 0;
	while (map->piece[i])
		ft_strdel(&map->piece[i++]);
	free(map->piece);
}