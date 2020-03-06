/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2020/03/06 15:59:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	ft_key(int key, t_map *map)
{
	if (53 == key)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (0);
}

void	ft_del_map(t_map *map)
{
	free(map->p1_name);
	free(map->p2_name);
	free(map);
}

void	ft_read(t_map *data)
{
	ft_putstr(data->p1_name);
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
	ft_put_image(map);
	mlx_key_hook(win, ft_key, map);
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
//	while (1)
//	{
	//	ft_read_plateau(&map);
	//	ft_draw(data);
	//	ft_put_image(data);
	//	if (-1 == ft_put_piece(&map, 0, 0))
	//		break ;
//	}
	//ft_del_map(map);
	return (0);
}
