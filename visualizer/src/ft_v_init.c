/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_v_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 18:35:58 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	ft_get_player(t_map **map)
{
	char	*line;
	char	*name;

	line = ft_find_line1((*map)->fd, "exec p1");
	//line = ft_strdup("exec p1 / /ff/ffffffffffffff");
	//if (!line)
	//	return;
	
	if ((*map)->fd)
		name = ft_strrchr(line, '/');
	else
		name = ft_strrchr(line, '/');
//	(*map)->p1_name = ft_strdup(name + 1);
//	(*map)->p1_name[ft_strlen((*map)->p1_name) - 8] = '\0';
//	ft_strdel(&line);
//	line = ft_find_line((*map)->fd, "exec p2");
/*	name = ft_strrchr(line, '/');
	(*map)->p2_name = ft_strdup(name + 1);
//	(*map)->p2_name[ft_strlen((*map)->p2_name) - 8] = '\0';
	ft_strdel(&line);
*/
}

void	ft_get_size(t_map **map)
{
	char	*line;
	int		max;

	line = ft_find_line1((*map)->fd, "Plateau");
	(*map)->map_height = ft_atoi(ft_strchr(line, ' '));
	(*map)->map_width = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	max = ft_max((*map)->map_height, (*map)->map_width);
	(*map)->frame_height = FR_HEIGHT * (*map)->map_height / max;
	(*map)->frame_width = FR_WIDTH * (*map)->map_width / max;
	(*map)->frame_y = HEIGHT - (*map)->frame_height - 50;
	(*map)->frame_x = (WIDTH	- (*map)->frame_width)/ 2;
}

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
