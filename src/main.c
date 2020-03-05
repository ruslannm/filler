/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 17:43:55 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_del_piece(t_map *map)
{
	int i;

	i = 0;
	while (i < map->piece_height)
		free(map->piece[i++]);
	free(map->piece);
}

void	ft_del_map(t_map *map, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(map->map[i++]);
	free(map->map);
}

void	ft_del_in_map(t_map *map, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(map->in_map[i++]);
	free(map->in_map);
}

int		main(void)
{
	t_map	*map;
	int		ret;
	int		fd;

	fd = 0;
	ret = ft_init(&map, fd);
	if (0 == ret)
	{
		while (1)
		{
			if (-1 == ft_read_plateau(&map))
				break ;
			if (-1 == ft_read_piece(&map))
				break ;
			ft_heat(&map);
			if (-1 == ft_put_piece(&map))
				break ;
		}
		ft_del_map(map, map->map_height);
		free(map);
	}
	return (ret);
}
