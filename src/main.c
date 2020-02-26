/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/02/26 16:32:15 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_del_piece(t_map *map)
{
	int i;

	i = 0;
	while (i < map->piece_height)
		ft_strdel(&map->piece[i++]);
	free(map->piece);
}

void	ft_del_map(t_map *map, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(&map->map[i++]);
	free(map->map);
}

int		main(void)
{
	t_map	*map;
	int		fd;

	fd = 0;
	if (!(map = ft_init(fd)))
		return (0);
	while (1)
	{
		ft_read_plateau(&map);
		if (-1 == ft_read_piece(&map))
			break ;
		ft_heat(&map);
		if (-1 == ft_put_piece(&map, 0, 0))
			break ;
	}
	ft_del_map(map, map->map_height);
	return (0);
}
