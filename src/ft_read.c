/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/02 18:48:33 by rgero            ###   ########.fr       */
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

void	ft_fill_line_map(t_map *map, int i, char *str)
{
	int	k;

	k = 0;
	while (k < map->map_width && str[k])
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
	int fd;

	line = ft_find_line(0, "000");
	i = 0;
	ft_fill_line_map(*map, i, line + 4);
	ft_strdel(&line);
	while (++i < (*map)->map_height)
	{
		get_next_line(0, &line);
		fd = open("filler.log", O_WRONLY | O_APPEND);
		ft_printf_fd(fd, "%s\n", line);
		close(fd);
		ft_fill_line_map(*map, i, line + 4);
		ft_strdel(&line);
	}
	ft_ini_last_corner(map);
	ft_get_last_corner(map);
}

int		ft_read_piece(t_map **map)
{
	int		i;

	if (-1 == ft_get_size_piece(map))
		return (-1);
	(*map)->piece_set = 0;
	(*map)->piece_h = 0;
	(*map)->piece_w = 0;
	if (!((*map)->piece =\
		(char**)malloc(sizeof(char *) * (*map)->piece_height)))
		return (-1);
	i = -1;
	while (++i < (*map)->piece_height)
		get_next_line(0, &(*map)->piece[i]);
	return (0);
}
