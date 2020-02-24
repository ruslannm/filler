/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 15:20:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_fill_line_map(t_map *map, int i, char *str)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if ('.' == str[k])
			map->map[i][k] = DOT;
		else
			map->map[i][k] =\
			(str[k] == map->player || str[k] == map->player + 32)\
			? PLAYER : ENEMY;
		k++;
	}
}

/*
** if fd != 0 - just test algorithm
*/

void	ft_read_plateau(t_map *map)
{
	char	*line;
	int		i;

	if (0 == map->fd)
	{
		get_next_line(map->fd, &line);
		ft_strdel(&line);
		get_next_line(map->fd, &line);
	}
	else
		line = ft_find_line(map->fd, "000");
	i = 0;
	ft_fill_line_map(map, i, line + 4);
	ft_strdel(&line);
	while (++i < map->map_height)
	{
		get_next_line(map->fd, &line);
		ft_fill_line_map(map, i, line + 4);
		ft_strdel(&line);
	}
}

void	ft_read_piece(t_map *map)
{
	char	*line;
	int		i;

	ft_get_size(map, "Piece");
	map->piece = ft_memalloc(sizeof(char *) * map->piece_height);
	line = NULL;
	i = -1;
	while (++i < map->piece_height)
		get_next_line(map->fd, &map->piece[i]);
}
