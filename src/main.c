/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 16:27:49 by rgero            ###   ########.fr       */
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

void	ft_del_map_last(t_map *map, int height)
{
	int i;

	i = 0;
	while (i < height)
		free(map->map_last[i++]);
	free(map->map_last);
}

void	ft_print_map(t_map *map)
{
	int	h;
	int	w;
	int fd1;

	fd1 = open("result1.txt", O_WRONLY | O_APPEND);
	h = 0;
	while (h < map->map_height)
	{
		w = 0;
		ft_printf_fd(fd1, "% 3d|", h);
		while (w < map->map_width)
		{
			ft_printf_fd(fd1, "% 3d", map->map[h][w]);
			w++;
		}
		ft_printf_fd(fd1, "\n");
		h++;
	}
	write(fd1, "----\n", 5);
	close(fd1);
}

void	ft_print_map_last(t_map *map)
{
	int	h;
	int	w;
	int fd1;

	fd1 = open("result1.txt", O_WRONLY | O_APPEND);
	h = 0;
	while (h < map->map_height)
	{
		w = 0;
		ft_printf_fd(fd1, "% 3d|", h);
		while (w < map->map_width)
		{
			ft_printf_fd(fd1, "% 3d", map->map_last[h][w]);
			w++;
		}
		ft_printf_fd(fd1, "\n");
		h++;
	}
	write(fd1, "----\n", 5);
	close(fd1);
}


int		main(void)
{
	t_map	*map;
	int		fd;

	fd = 0;// open("filler2.txt", O_RDONLY);;
	if (!(map = ft_init(fd)))
		return (0);
	while (1)
	{
		ft_read_plateau(&map);
		if (-1 == ft_read_piece(&map))
			break ;
		ft_heat(&map);
//		ft_heat_last(&map);
//		ft_print_map(map);
//		ft_print_map_last(map);
		if (-1 == ft_put_piece(&map, 0, 0))
			break ;
	}
	ft_del_map(map, map->map_height);
	free(map);
	return (0);
}
