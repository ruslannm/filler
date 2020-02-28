/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 16:44:10 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_get_player(t_map **map)
{
	char	*line;

	if (0 == (*map)->fd)
		get_next_line((*map)->fd, &line);
	else
		line = ft_find_line((*map)->fd, "exec p");
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

int		ft_get_map(t_map **map)
{
	int	height;

	if (!((*map)->map = (int **)malloc(sizeof(int *) * (*map)->map_height)))
		return (-1);
	height = 0;
	while (height < (*map)->map_height)
	{
		if (!((*map)->map[height++] =\
		(int*)malloc(sizeof(int) * (*map)->map_width)))
		{
			ft_del_map(*map, height);
			return (-1);
		}
	}
	return (0);
}

t_map	*ft_init(int fd)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->fd = fd;
	ft_get_player(&map);
	ft_get_size(&map, "Plateau");
	if (-1 == ft_get_map(&map))
	{
		free(map);
		return (NULL);
	}
	return (map);
}
