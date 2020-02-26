/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/02/26 15:56:05 by rgero            ###   ########.fr       */
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
		ft_printf_fd(map->fd_log, "% 3d|", h);

		while (w < map->map_width)
		{
			ft_printf_fd(map->fd_log, "% 3d", map->map[h][w]);
			w++;
		}
		ft_printf_fd(map->fd_log, "\n");
		h++;
	}
	ft_printf_fd(map->fd_log, "---\n");
}

int	main(void)
{
	t_map	*map;
	int		fd;

//	fd = open("filler2.txt", O_RDONLY);
	fd = 0;
	map = ft_init(fd);
	map->fd_log = open("result1.txt", O_WRONLY | O_APPEND);
	while (1)
	{
		ft_read_plateau(&map);
//		ft_print_map(map);
		ft_read_piece(&map);
		ft_heat(&map);
//		ft_print_map(map);
		if (-1 == ft_put_piece(&map))
			break ;
	}
	close(map->fd_log);
//	ft_del_map(map);
	return (0);
}