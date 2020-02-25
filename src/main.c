/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/02/25 16:13:51 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

int	main(void)
{
	t_map *map;
	int		fd;
	int fd1;

//	fd = open("filler2.txt", O_RDONLY);
	fd = 0;
	fd1 = open("result1.txt", O_WRONLY | O_APPEND);
	write(fd1, "start", 5);
	close(fd1);
	map = ft_init(fd);
	while (1)
	{
		ft_read_plateau(map);
		ft_print_map(map);
		ft_read_piece(map);
		ft_heat(map);
		ft_print_map(map);
		ft_put_piece(map);
		ft_del_piece(map);
		if (fd)
		{
			close(fd);
			break ;
		}
	}
//	ft_del_map(map);
//	ft_print_map(map);
	return (0);
}