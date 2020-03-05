/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 14:46:58 by rgero            ###   ########.fr       */
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


int	ft_read_plateau(t_map **map)
{
	char	*line;
	int		i;
	int 	ret;

	get_next_line((*map)->fd, &line);
	if (0 == ft_strncmp("Plateau", line, 7))
	{
		ft_strdel(&line);
		get_next_line((*map)->fd, &line);
	}
	ft_strdel(&line);
	if (!((*map)->in_map =\
		(char**)malloc(sizeof(char *) * (*map)->map_height)))
		return (-1);
	i = -1;
	while (++i < (*map)->map_height)
		get_next_line((*map)->fd, &(*map)->in_map[i]);
	ret = ft_control_plateau(map);
	if (0 == ret)
	{
		ft_ini_last_corner(map);
		ft_get_last_corner(map);
	}
	if (-1 == (*map)->opposite_reach)
		ft_get_opposite_corner(map);
	return (ret);
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

int		ft_read_piece(t_map **map)
{
	int		i;
	int 	ret;

	if (-1 == ft_get_size_piece(map))
		return (-1);
	(*map)->direction = ((*map)->direction ? 0 : 1);
	(*map)->piece_set = 0;
	(*map)->piece_h = 0;
	(*map)->piece_w = 0;
	(*map)->piece_min_distance =\
		4 * ft_max((*map)->map_height, (*map)->map_width);
	(*map)->piece_min_distance_opposite =\
		4 * ft_max((*map)->map_height, (*map)->map_width);
	if (!((*map)->piece =\
		(char**)malloc(sizeof(char *) * (*map)->piece_height)))
		return (-1);
	i = -1;
	while (++i < (*map)->piece_height)
		get_next_line((*map)->fd, &(*map)->piece[i]);
	ret = ft_control_piece(map);
	if (-1 == ret)
		ft_del_piece(*map);
	else
		ft_get_shape_corner(map);
	return (ret);
}
