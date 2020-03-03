/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/03/03 19:21:32 by rgero            ###   ########.fr       */
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
	i = 0;
	while (i < height)
		free(map->in_map[i++]);
	free(map->in_map);

}

void	ft_del_in_map(t_map *map, int height)
{
	int i;

	i = 0;
	i = 0;
	while (i < height)
		free(map->in_map[i++]);
	free(map->in_map);
}

/*
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
	ft_printf_fd(map->fd_log, "----\n");
}
*/
int		main(void)
{
	t_map	*map;
	int		ret;
	int fd;

	fd = 0; //open("filler2.txt", O_RDONLY);

	ret = ft_init(&map, fd);
	if (0 == ret)
	{
		while (1)
		{
			if (-1 == ft_read_plateau(&map))
				break;
			if (-1 == ft_read_piece(&map))
				break ;
			ft_heat(&map);
			if (-1 == ft_put_piece(&map, 0, 0))
				break ;
		}
		ft_del_map(map, map->map_height);
		free(map);
	}
	close (fd);
	return (ret);
}
