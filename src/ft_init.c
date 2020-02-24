/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 12:43:30 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_find_line(int fd, char *needle)
{
	char	*ret;

	while (get_next_line(fd, &ret))
	{
		if (ft_strstr(ret, needle))
			break ;
		ft_strdel(&ret);
	}
	return (ret);
}

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

void	ft_get_size(t_map *map)
{
	char	*line;

	if (0 == map->fd)
		get_next_line(map->fd, &line);
	else
		line = ft_find_line(map->fd, "Plateau");
	map->plateau->height = ft_atoi(ft_strchr(line, ' '));
	map->plateau->width = ft_atoi(ft_strrchr(line, ' '));
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

t_map	*ft_init(int fd)
{
	t_map *map;

	map = (t_map*)malloc(sizeof(t_map));
	map->fd = fd;
	ft_get_player(map);
	map->plateau = (t_object*)malloc(sizeof(t_object));
	ft_get_size(map);
	ft_read_plateau(map);
	return (map);
}