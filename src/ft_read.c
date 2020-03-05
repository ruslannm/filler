/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 17:55:34 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_read_plateau(t_map **map)
{
	char	*line;
	int		ret;

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
	ret = -1;
	while (++ret < (*map)->map_height)
		get_next_line((*map)->fd, &(*map)->in_map[ret]);
	ret = ft_control_plateau(map);
	if (0 == ret)
	{
		ft_ini_last_corner(map);
		ft_get_last_corner(map);
		if (-1 == (*map)->opposite_reach)
			ft_get_opposite_corner(map);
	}
	return (ret);
}

int	ft_read_piece(t_map **map)
{
	int	i;
	int	ret;

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
