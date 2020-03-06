/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/06 17:04:59 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	ft_get_player_2(t_map **map)
{
	char	*line;
	char	*name;
	int		ret;

	ret = 0;
	line = ft_find_line(0, "$$$ exec p2");
	if (!line)
		ret = -1;
	else
	{
		name = ft_strrchr(line, '/');
		if (!((*map)->p2_name = ft_strdup(name + 1)))
			ret = -1;
		else
			(*map)->p2_name[ft_strlen((*map)->p2_name) - 8] = '\0';
	}
	ft_strdel(&line);
	return (ret);
}

int	ft_get_player(t_map **map)
{
	char	*line;
	char	*name;
	int		ret;

	ret = 0;
	line = ft_find_line(0, "$$$ exec p1");
	if (!line)
		ret = -1;
	else
	{
		name = ft_strrchr(line, '/');
		if (!((*map)->p1_name = ft_strdup(name + 1)))
			ret = -1;
		else
			(*map)->p1_name[ft_strlen((*map)->p1_name) - 8] = '\0';
	}
	ft_strdel(&line);
	if (0 == ret)
	{
		ret = ft_get_player_2(map);
		if (-1 == ret)
			free((*map)->p1_name);
	}
	return (ret);
}

int	ft_get_size_map(t_map **map)
{
	char	*line;
	int		ret;
	char	*height;
	char	*width;

	ret = 0;
	get_next_line(0, &line);
	if (ft_strncmp("Plateau ", line, 8))
		ret = -1;
	else if (ft_strlen(line) < 12)
		ret = -1;
	else
	{
		height = ft_strchr(line, ' ') + 1;
		width = ft_strrchr(line, ' ') + 1;
		if (ft_isdigit(height[0]) && ft_isdigit(width[0]))
		{
			(*map)->map_height = ft_atoi(height);
			(*map)->map_width = ft_atoi(width);
		}
		else
			ret = -1;
	}
	ft_strdel(&line);
	return (ret);
}

int		ft_get_size_frame(t_map **map)
{
	int	ret;
	int	height_ratio;
	int	width_ratio;

	ret = ft_get_size_map(map);
	if (-1 == ret)
		return (ret);
	height_ratio = FR_HEIGHT / (*map)->map_height;
	width_ratio = FR_WIDTH / (*map)->map_width;
	(*map)->frame_ratio = ft_min(height_ratio, width_ratio);
	(*map)->frame_height = (*map)->map_height * (*map)->frame_ratio;
	(*map)->frame_width = (*map)->map_width * (*map)->frame_ratio;
	(*map)->frame_y = HEIGHT - (*map)->frame_height - 50;
	(*map)->frame_x = (WIDTH - (*map)->frame_width)/ 2;
	return (ret);
}

int	ft_init(t_map **map)
{
	int	ret;

	ret = 0;
	if (!(*map = (t_map*)malloc(sizeof(t_map))))
		return (-1);
	if (-1 == ft_get_player(map))
		ret = -1;
	else if (-1 == ft_get_size_frame(map))
		ret = -1;
	if (-1 == ret)
	{
		free(*map);
		return (ret);
	}
	return (ret);
}

/*
t_map	*ft_init(int fd)
{
	t_map	*map;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->fd = fd;
	ft_get_player(&map);
	exit(0);
//	ft_get_size(&map);
	return (map);
}
*/