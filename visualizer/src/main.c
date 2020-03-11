/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2020/03/11 15:18:11 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		ft_key(int key, t_map *map)
{
	(void)map;
	if (53 == key)
	{
		mlx_destroy_image(map->mlx_ptr, map->img_ptr);
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		free(map);
		exit(0);
	}
	return (0);
}

static int	ft_close_window(void *param)
{
	(void)param;
	exit(0);
}

void	ft_put_windows(t_map *map)
{
	void	*mlx;
	void	*win;

	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, WIDTH, HEIGHT, "filler");
	mlx = map->mlx_ptr;
	win = map->win_ptr;
	map->img_ptr = mlx_new_image(mlx, WIDTH, HEIGHT);
	map->data = mlx_get_data_addr(map->img_ptr, &(map->bpp),
		&(map->sl), &(map->endian));
	ft_fill_bg(&map);
	ft_fill_bit_menu(&map, 20, 250, P1COLOR);
	ft_fill_bit_menu(&map, 20, 700, P2COLOR);
	mlx_loop_hook(mlx, ft_put_image, map);
	mlx_hook(win, 17, 0, ft_close_window, map);
	mlx_hook(win, 2, 0, ft_key, map);
	mlx_loop(mlx);
}

int		main(void)
{
	int		ret;
	t_map	*map;

	ret = ft_init(&map);
	if (0 == ret)
	{
		ft_put_windows(map);
		return (0);
	}
	return (0);
}
