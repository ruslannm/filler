/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/03/03 15:23:23 by rgero            ###   ########.fr       */
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

int		main(void)
{
	t_map	*map;
	int		ret;
	int fd;
	int fd_log;

	fd = open("filler2.txt", O_RDONLY);

	fd_log = open("filler.log", O_WRONLY | O_APPEND);
	
	ret = ft_init(&map, fd, fd_log);
	

	ft_printf_fd(fd_log, "ft_init=%d\n", ret);
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
	close (fd_log);
	return (ret);
}
