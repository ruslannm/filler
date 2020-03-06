/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/06 18:13:21 by rgero            ###   ########.fr       */
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


void	ft_read_plateau(t_map **map)
{
	char	*line;
	int		i;

	line = ft_find_line(0, "000");
	i = 0;
	ft_fill_line_map(map, i, line + 4);
	ft_strdel(&line);
	while (++i < (*map)->map_height)
	{
		get_next_line(0, &line);
		ft_fill_line_map(map, i, line + 4);
		ft_strdel(&line);
	}
}
