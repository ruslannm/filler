/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 17:02:32 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_map(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->map_height)
	{
		w = 0;
		while (w < map->map_width)
		{
			ft_printf("% 3d", map->map[h][w]);
			w++;
		}
		ft_printf("\n");
		h++;
	}
}

int	main(void)
{
	t_map *map;
	int		fd;

	fd = open("filler2.txt", O_RDONLY);
//	fd = 0;
	map = ft_init(fd);
	while (1)
	{
		ft_read_plateau(map);
		ft_read_piece(map);
		ft_heat(map);
		ft_put_piece(map);
//		ft_del_piece(map);
		if (fd)
		{
			close(fd);
			break ;
		}
	}
//	ft_del_map(map);
	ft_print_map(map);
	return (0);
}