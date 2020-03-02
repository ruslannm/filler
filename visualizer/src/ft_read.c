/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 18:26:27 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_plateau(t_map **map)
{
	char	*line;
	int		i;

	line = ft_find_line((*map)->fd, "000");
	i = 0;
	ft_fill_line_map(*map, i, line + 4);
	ft_strdel(&line);
	while (++i < (*map)->map_height)
	{
		get_next_line((*map)->fd, &line);
		ft_fill_line_map(*map, i, line + 4);
		ft_strdel(&line);
	}
}