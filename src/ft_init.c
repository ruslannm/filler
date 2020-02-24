/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 13:18:21 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** if fd != 0 - just test algorithm
*/

void	ft_get_player(t_map *map)
{
	char	*line;

	if (0 == map->fd)
		get_next_line(map->fd, &line);
	else
		line = ft_find_line(map->fd, "exec p");
	map->player = 70 + (line[10] - '0') * 9;
	map->enemy = 97 - (line[10] - '0') * 9;
	ft_strdel(&line);
}

void	ft_get_size(int	fd, t_object *object, char *str)
{
	char	*line;

	if (0 == fd)
		get_next_line(fd, &line);
	else
		line = ft_find_line(fd, str);
	object->height = ft_atoi(ft_strchr(line, ' '));
	object->width = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
}

void	ft_read_plateau(t_map *map)
{
	char	*line;
	int		i;

	map->plateau->info = ft_memalloc(sizeof(char *) * map->plateau->height);
	if (0 == map->fd)
	{
		get_next_line(map->fd, &line);
		ft_strdel(&line);
		get_next_line(map->fd, &line);
	}
	else
		line = ft_find_line(map->fd, "000");
	i = -1;
	map->plateau->info[++i] = ft_strdup(line + 4);
	ft_strdel(&line);
	while (++i < map->plateau->height)
	{
		get_next_line(map->fd, &line);
		map->plateau->info[i] = ft_strdup(line + 4);
		ft_strdel(&line);
	}
}

void	ft_read_piece(t_map *map)
{
	char	*line;
	int		i;

	map->piece->info = ft_memalloc(sizeof(char *) * map->piece->height);
	line = NULL;
	i = -1;
	while (++i < map->piece->height)
		get_next_line(map->fd, &map->piece->info[i]);
}

t_map	*ft_init(int fd)
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	map->fd = fd;
	ft_get_player(map);
	map->plateau = (t_object*)malloc(sizeof(t_object));
	ft_get_size(map->fd, map->plateau, "Plateau");
	ft_read_plateau(map);
	map->piece = (t_object*)malloc(sizeof(t_object));
	ft_get_size(map->fd, map->piece, "Piece");
	ft_read_piece(map);
	return (map);
}