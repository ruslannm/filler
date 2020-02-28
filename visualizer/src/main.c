/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 17:35:55 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	ft_put_windows(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "filler:");
	data->img_ptr = mlx_new_image(data->mlx_ptr, 1000, 1000);
	data->data = mlx_get_data_addr(data->img_ptr, &(data->bpp),
		&(data->sl), &(data->endian));
	ft_draw(data);
	ft_put_image(data);
	mlx_key_hook(data->win_ptr, ft_key, data);
	mlx_mouse_hook(data->win_ptr, ft_mouse, data);
	mlx_loop(data->mlx_ptr);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_fdf	*data;

	t_map	*map;
	int		fd;

	fd = 0;
	if (!(map = ft_init(fd)))
		return (0);
	while (1)
	{
		ft_read_plateau(&map);
		if (-1 == ft_read_piece(&map))
			break ;
		ft_heat(&map);
		if (-1 == ft_put_piece(&map, 0, 0))
			break ;
	}
	ft_del_map(map, map->map_height);
	free(map);


	if (!(2 == argc || 4 == argc))
		ft_err_exit("usage: ./fdf <filename> [case_size z_size]");
	if ((fd = open(argv[1], O_RDONLY | O_DIRECTORY)) > 0)
		ft_err_exit("No data found.");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_err_exit("No data found.");
	data = ft_data_ini();
	if (data)
	{
		ft_read_argv(data, argc, argv);
		if (-1 == ft_read(fd, &data, NULL, 0))
			ft_err_exit("Found wrong line length. Exiting.");
		else if (data->height <= 0)
			ft_err_exit("No data found.");
		else
			ft_put_windows(data);
	}
	else
		ft_err_exit("error");
	ft_data_delete(data);
	return (0);
}
