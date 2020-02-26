/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/26 15:39:45 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** if fd != 0 - just test algorithm
*/

void	ft_get_player(t_map **map)
{
	char	*line;
//	int		fd;

//	fd = open("trace.txt", O_WRONLY | O_APPEND);
	//write(fd, "start", 5);

	if (0 == (*map)->fd)
		get_next_line((*map)->fd, &line);
	else
		line = ft_find_line((*map)->fd, "exec p");
//	write(fd, line, ft_strlen(line));
	//close(fd);
	(*map)->player = 70 + (line[10] - '0') * 9;
	(*map)->enemy = 97 - (line[10] - '0') * 9;
	ft_strdel(&line);
}

void	ft_get_size(t_map **map, char *str)
{
	char	*line;

	if (0 == (*map)->fd)
		get_next_line((*map)->fd, &line);
	else
		line = ft_find_line((*map)->fd, str);
	if (0 == ft_strcmp("Plateau", str))
	{
		(*map)->map_height = ft_atoi(ft_strchr(line, ' '));
		(*map)->map_width = ft_atoi(ft_strrchr(line, ' '));
	}
	else
	{
		(*map)->piece_height = ft_atoi(ft_strchr(line, ' '));
		(*map)->piece_width = ft_atoi(ft_strrchr(line, ' '));
	}
	ft_strdel(&line);
}

t_map	*ft_init(int fd)
{
	t_map	*map;
	int		height;

	map = (t_map*)malloc(sizeof(t_map));
	map->fd = fd;
	ft_get_player(&map);
	ft_get_size(&map, "Plateau");
	map->map = (int **)malloc(sizeof(int *) * map->map_height);
	height = 0;
	while (height < map->map_height)
		map->map[height++] =\
		(int*)malloc(sizeof(int) * map->map_width);
	return (map);
}
