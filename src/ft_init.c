/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/04 19:42:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_get_player(t_map **map)
{
	char	*line;
	int		ret;

	get_next_line((*map)->fd, &line);
	if (ft_strncmp("$$$ exec p", line, 10))
		ret = -1;
	else
	{
		if (ft_strlen(line) > 10 && ('1' == line[10] || '2' == line[10]))
		{
			(*map)->player = 70 + (line[10] - '0') * 9;
			(*map)->enemy = 97 - (line[10] - '0') * 9;
			ret = 0;
		}
		else
			ret = -1;
	}
	ft_strdel(&line);
	return (ret);
}

int	ft_get_size_map(t_map **map)
{
	char	*line;
	int		ret;
	char	*height;
	char	*width;

	ret = 0;
	get_next_line((*map)->fd, &line);
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

int	ft_get_map(t_map **map)
{
	int	height;

	if (!((*map)->map = (int **)malloc(sizeof(int *) * (*map)->map_height)))
		return (-1);
	height = 0;
	while (height < (*map)->map_height)
	{
		if (!((*map)->map[height] =\
		(int*)malloc(sizeof(int) * (*map)->map_width)))
		{
			ft_del_map(*map, height);
			return (-1);
		}
		height++;
	}
	return (0);
}

int	ft_init(t_map **map, int fd)
{
	int	ret;

	ret = 0;
	if (!(*map = (t_map*)malloc(sizeof(t_map))))
		return (-1);
	(*map)->fd = fd;
	if (-1 == ft_get_player(map))
		ret = -1;
	else if (-1 == ft_get_size_map(map))
		ret = -1;
	else if (-1 == ft_get_map(map))
		ret = -1;
	if (-1 == ret)
	{
		free(*map);
		return (ret);
	}
	(*map)->direction = 0;
	(*map)->opposite_reach = 0;
	(*map)->piece_last_distance_opposite =\
		4 * ft_max((*map)->map_height, (*map)->map_width);

	(*map)->opposite_corner[0] = 0;
	(*map)->opposite_corner[1] = 0;
	(*map)->opposite_corner[2] = 0;
	(*map)->opposite_corner[3] = 0;
	return (ret);
}
