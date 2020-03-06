/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:10:56 by rgero             #+#    #+#             */
/*   Updated: 2020/03/06 16:01:08 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	ft_put_image(t_map *map)
{
	void	*mlx;
	void	*win;

	ft_fill_bg(map);
	mlx = map->mlx_ptr;
	win = map->win_ptr;
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img_ptr, 0, 0);
	mlx_string_put(mlx, win, 10, 20, 0xFFFFFF, "Exit: ESCAPE");
	mlx_string_put(mlx, win, 200, 20, 0xFFFFFF, map->p1_name);
	mlx_string_put(mlx, win, 500, 20, 0xFFFFFF, map->p2_name);
}

/*
t_fdf	*ft_data_ini(void)
{
	t_fdf	*data;

	data = NULL;
	if ((data = (t_fdf*)malloc(sizeof(t_fdf))))
	{
		data->in_tab = NULL;
		data->tab = NULL;
		data->data = NULL;
	}
	return (data);
}

void	ft_data_delete(t_fdf *data)
{
	if (data)
	{
		if (data->in_tab)
			free(data->in_tab);
		if (data->tab)
			free(data->tab);
		if (data->data)
			free(data->data);
		free(data);
	}
}
*/