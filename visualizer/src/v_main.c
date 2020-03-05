/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 19:26:00 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

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

void	ft_put_windows(t_map *data)
{
//	void	*mlx;
//	void	*win;
	
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "filler:");
//	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
/*	data->data = mlx_get_data_addr(data->img_ptr, &(data->bpp),
		&(data->sl), &(data->endian));
*/
/*	while (1)
	{
		mlx = data->mlx_ptr;
		win = data->win_ptr;
		mlx_string_put(mlx, win, 115, 20, 0xFFFFFF, "Menu");
	}
*/
	//mlx_loop(data->mlx_ptr);
}

int		main(void)
{
	int		fd;
	t_map	*map;
	
	fd = open("./visualizer/result1.txt", O_RDONLY); // 0;
	if (!(map = ft_init(fd)))
		return (0);
//	ft_put_windows(map);
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
