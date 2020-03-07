/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/07 13:16:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		ft_fill_line_map(t_map **map, int i, char *str)
{
	int	ret;
	int	k;
	int h;
	int w;

	ret = ft_strlen(str);
//	ft_printf("ft_strlen(str):%d map_width=%d\n", ret,  (*map)->map_width);
	ret = (ret == (*map)->map_width + 4 ? 0 : -1);
	k = 4;
	h = (*map)->frame_y + (*map)->frame_ratio * i;
	while (k < (*map)->map_width + 4 && 0 == ret)
	{
		w = (*map)->frame_x + (*map)->frame_ratio * (k - 4);
		if (str[k] == 'O' || str[k] == 'o')
			ft_fill_bit(map, h, w, P1COLOR);
		else if (str[k] == 'X' || str[k] == 'x')
			ft_fill_bit(map, h, w, P2COLOR);
		k++;
	}
	return (ret);
}


int	ft_read_plateau(t_map **map)
{
	char	*line;
	int		i;
	int		ret;

	ret = ft_find_line(&line, "000");
	if (0 >= ret)
		return (1);
	if (0 == ft_strncmp("== O fin:", line, 9))
	{
		ft_strcat((*map)->p1_name, line + 8);
		ft_strdel(&line);
		get_next_line(0, &line);
		if (0 == ft_strncmp("== X fin:", line, 9))
			ft_strcat((*map)->p2_name, line + 8);
		ft_strdel(&line);
		return (1);
	}
	else if (0 == ft_strncmp("== X fin:", line, 9))
	{
		ft_strcat((*map)->p2_name, line + 8);
		ft_strdel(&line);
		return (1);
	}
	i = 0;
	ft_fill_line_map(map, i, line);
	ft_strdel(&line);
	while (++i < (*map)->map_height)
	{
		get_next_line(0, &line);
		ft_fill_line_map(map, i, line);
		ft_strdel(&line);
	}
	return (0);
}
