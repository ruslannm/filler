/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 14:53:56 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	corner[4] - coordinates of  rectangle
*/

void	ft_ini_corner(int **corner)
{
	*corner[0] = -1;
	*corner[1] = -1;
	*corner[2] = -1;
	*corner[3] = -1;
}

void	ft_set_corner(int **corner, int h, int w)
{
	if (-1 == *corner[0])
	{
		*corner[0] = h;
		*corner[1] = h;
	}
	if (h > *corner[1])
		*corner[1] = h;
	if (-1 == *corner[2])
	{
		*corner[2] = w;
		*corner[3] = w;
	}
	if (w < *corner[2])
		*corner[2] = w;

	if (w > *corner[3])
		*corner[3] = w;
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
				ft_set_corner(&((*map)->last_corner), h, w);
			w++;
		}
		h++;
	}
}

void	ft_fill_line_map(t_map *map, int i, char *str)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if ('.' == str[k])
			map->map[i][k] = DOT;
		else
		{
			if (str[k] == map->enemy)
				map->map[i][k] = ENEMY;
			else if (str[k] == map->enemy + 32)
				map->map[i][k] = LAST;
			else
				map->map[i][k] = PLAYER;
		}
		k++;
	}
}

void	ft_read_plateau(t_map **map)
{
	char	*line;
	int		i;

	line = ft_find_line((*map)->fd, "000");
	i = 0;
	ft_fill_line_map(*map, i, line + 4);
	ft_strdel(&line);
	while (++i < (*map)->map_height)
	{
		get_next_line((*map)->fd, &line);
		ft_fill_line_map(*map, i, line + 4);
		ft_strdel(&line);
	}
	ft_ini_corner(&((*map)->last_corner));
	ft_get_last_corner(map);
}

int		ft_read_piece(t_map **map)
{
	int		i;

	ft_get_size(map, "Piece");
	(*map)->piece_set = 0;
	(*map)->piece_h = 0;
	(*map)->piece_w = 0;
	if (!((*map)->piece =\
		(char**)malloc(sizeof(char *) * (*map)->piece_height)))
		return (-1);
	i = -1;
	while (++i < (*map)->piece_height)
		get_next_line((*map)->fd, &(*map)->piece[i]);
	return (0);
}
