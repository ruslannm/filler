/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:10:56 by rgero             #+#    #+#             */
/*   Updated: 2020/03/07 15:32:42 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int	ft_put_image(t_map *map)
{
	void	*mlx;
	void	*win;
	int		ret;

	mlx = map->mlx_ptr;
	win = map->win_ptr;
	ret = ft_read_plateau(&map);
//	if (0 == ret)
//	{
		mlx_put_image_to_window(mlx, win, map->img_ptr, 0, 0);
		mlx_string_put(mlx, win, 10, 20, 0xFFFFFF, "Exit: ESCAPE");
		mlx_string_put(mlx, win, 300, 20, P1COLOR, map->p1_name);
		mlx_string_put(mlx, win, 750, 20, P2COLOR, map->p2_name);
//	}
	return (0);
}
