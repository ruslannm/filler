/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:26:58 by rgero             #+#    #+#             */
/*   Updated: 2020/03/03 18:58:34 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_check(t_map *map, int h, int w)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	i = map->shape_corner[0];
	while (i <= map->shape_corner[1])
	{
		j = map->shape_corner[2];
		while (j <= map->shape_corner[3])
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

void	ft_control(t_map **map, int h, int w)
{
	int	control[2];

	control[0] = ft_get_sum(*map, h, w);
	control[1] = ft_get_distance(map, h, w);
	if ((*map)->direction)
	{
		if (control[0] <= (*map)->piece_min_summa &&\
			control[1] <= (*map)->piece_min_distance)
			ft_set_piece(map, control, h, w);
	}
	else
	{
		if (control[0] < (*map)->piece_min_summa &&\
			control[1] < (*map)->piece_min_distance)
			ft_set_piece(map, control, h, w);
	}

//	if (control[0] <= (*map)->piece_min_summa)
//		ft_set_piece(map, control, h, w);
}

int		ft_put_piece(t_map **map, int h, int w)
{
	h = -(*map)->shape_corner[0];
	while (h + (*map)->shape_corner[1] < (*map)->map_height)
	{
		w = -(*map)->shape_corner[2];
		while (w + (*map)->shape_corner[3] < (*map)->map_width)
		{
			if (ft_check(*map, h, w))
				ft_control(map, h, w);
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
