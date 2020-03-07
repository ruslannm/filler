/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 12:26:07 by rgero             #+#    #+#             */
/*   Updated: 2020/03/07 15:41:39 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"
/*
void	ft_put_pixel(t_map *map, int x, int y, int color)
{
	*(int*)(map->data + (x + y * WIDTH) * map->bpp / 8) = color;
}
*/

void	ft_fill_bg(t_map **map)
{
	int	i;
	int	*img;
	int	div;
	int	rem;

	ft_bzero((*map)->data, HEIGHT * WIDTH * ((*map)->bpp / 8));
	img = (int*)((*map)->data);
	i = -1;
	while (++i < HEIGHT * WIDTH)
	{
		div = i / WIDTH;
		rem = i % WIDTH;
		if (div >= (*map)->frame_y &&\
			div < (*map)->frame_y + (*map)->frame_height &&\
			rem >= (*map)->frame_x &&\
			rem < (*map)->frame_x + (*map)->frame_width)
			img[i] = FRCOLOR;
		else
			img[i] = BGCOLOR;
	}
}

void	ft_fill_bit(t_map **map, int y, int x, int color)
{
	int	i;
	int	*img;
	int	div;
	int	rem;

	img = (int*)((*map)->data);
	i = -1 + y * WIDTH + x;
	while (++i < (y + (*map)->frame_ratio) * WIDTH + x + (*map)->frame_ratio)
	{
		div = i / WIDTH;
		rem = i % WIDTH;
		if (div >= y && div < y + (*map)->frame_ratio &&\
			rem >= x && rem < x + (*map)->frame_ratio)
			img[i] = color;
	}
}

void	ft_fill_bit_last(t_map **map, int y, int x, int color)
{
	int	i;
	int	*img;
	int	div;
	int	rem;

	img = (int*)((*map)->data);
	i = -1 + y * WIDTH + x;
	while (++i < (y + (*map)->frame_ratio) * WIDTH + x + (*map)->frame_ratio)
	{
		div = i / WIDTH;
		rem = i % WIDTH;
		if (div >= y && div < y + (*map)->frame_ratio &&\
			rem >= x && rem < x + (*map)->frame_ratio &&\
			i % 2 == 0)
			img[i] = color;
	}
}


void	ft_fill_bit_menu(t_map **map, int y, int x, int color)
{
	int	i;
	int	*img;
	int	div;
	int	rem;

	img = (int*)((*map)->data);
	i = -1 + y * WIDTH + x;
	while (++i < (y + MENU_RATIO) * WIDTH + x + MENU_RATIO)
	{
		div = i / WIDTH;
		rem = i % WIDTH;
		if (div >= y && div < y + MENU_RATIO &&\
			rem >= x && rem < x + MENU_RATIO)
			img[i] = color;
	}
}
