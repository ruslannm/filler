/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:56:41 by rgero             #+#    #+#             */
/*   Updated: 2020/02/26 19:40:32 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_put_distance(t_map **map, int h, int w)
{
	int	i;

	i = (-1 == (*map)->map[h][w] ? 0 : (*map)->map[h][w]) + 1;
	if (h > 0)
	{
		if ((*map)->map[h - 1][w] == DOT)
			(*map)->map[h - 1][w] = i;
		if ((*map)->map[h - 1][w + 1] == DOT && w < (*map)->map_width - 1)
			(*map)->map[h - 1][w + 1] = i;
		if ((*map)->map[h - 1][w - 1] == DOT && w > 0)
			(*map)->map[h - 1][w - 1] = i;
	}
	if ((*map)->map[h][w + 1] == DOT && w < (*map)->map_width - 1)
		(*map)->map[h][w + 1] = i;
	if ((*map)->map[h][w - 1] == DOT && w > 0)
		(*map)->map[h][w - 1] = i;
	if (h < (*map)->map_height - 1)
	{
		if ((*map)->map[h + 1][w] == DOT)
			(*map)->map[h + 1][w] = i;
		if ((*map)->map[h + 1][w + 1] == DOT && w < (*map)->map_width - 1)
			(*map)->map[h + 1][w + 1] = i;
		if ((*map)->map[h + 1][w - 1] == DOT && w > 0)
			(*map)->map[h + 1][w - 1] = i;
	}
}

void	ft_put_distance_last(t_map **map, int h, int w)
{
	int	i;

	i = (-1 == (*map)->map_last[h][w] ? 0 : (*map)->map_last[h][w]) + 1;
	if (h > 0)
	{
		if ((*map)->map_last[h - 1][w] == DOT)
			(*map)->map_last[h - 1][w] = i;
		if ((*map)->map_last[h - 1][w + 1] == DOT && w < (*map)->map_width - 1)
			(*map)->map_last[h - 1][w + 1] = i;
		if ((*map)->map_last[h - 1][w - 1] == DOT && w > 0)
			(*map)->map_last[h - 1][w - 1] = i;
	}
	if ((*map)->map_last[h][w + 1] == DOT && w < (*map)->map_width - 1)
		(*map)->map_last[h][w + 1] = i;
	if ((*map)->map_last[h][w - 1] == DOT && w > 0)
		(*map)->map_last[h][w - 1] = i;
	if (h < (*map)->map_height - 1)
	{
		if ((*map)->map_last[h + 1][w] == DOT)
			(*map)->map_last[h + 1][w] = i;
		if ((*map)->map_last[h + 1][w + 1] == DOT && w < (*map)->map_width - 1)
			(*map)->map_last[h + 1][w + 1] = i;
		if ((*map)->map_last[h + 1][w - 1] == DOT && w > 0)
			(*map)->map_last[h + 1][w - 1] = i;
	}
}

void	ft_heat(t_map **map)
{
	int	h;
	int	w;
	int	max;
	int	i;

	max = 2 * ((*map)->map_height > (*map)->map_width\
		? (*map)->map_height : (*map)->map_width);
	i = -1;
	while (i < max)
	{
		h = 0;
		while (h < (*map)->map_height)
		{
			w = 0;
			while (w < (*map)->map_width)
			{
				if ((*map)->map[h][w] == i)
					ft_put_distance(map, h, w);
				w++;
			}
			h++;
		}
		i++;
	}
}

void	ft_clear_last(t_map **map)
{
	int	h;
	int	w;

	h = 0;
	while (h < (*map)->map_height)
	{
		w = 0;
		while (w < (*map)->map_width)
		{
			if (LAST == (*map)->map[h][w])
				(*map)->map_last[h][w] = LAST;
			else
				(*map)->map_last[h][w] = DOT;
			w++;
		}
		h++;
	}
}


void	ft_heat_last(t_map **map)
{
	int	h;
	int	w;
	int	max;
	int	i;

	ft_clear_last(map);
	max = 2 * ((*map)->map_height > (*map)->map_width\
		? (*map)->map_height : (*map)->map_width);
	i = -1;
	while (i < max)
	{
		h = 0;
		while (h < (*map)->map_height)
		{
			w = 0;
			while (w < (*map)->map_width)
			{
				if ((*map)->map_last[h][w] == i)
					ft_put_distance_last(map, h, w);
				w++;
			}
			h++;
		}
		i++;
	}
}

