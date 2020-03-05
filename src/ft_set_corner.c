/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 17:52:59 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	corner[4] - coordinates of  rectangle
**	0, 2----
**	|		|
**	|		|
**	 ----1, 3
*/

void	ft_set_last_corner(t_map **map, int h, int w)
{
	if (-1 == (*map)->last_corner[0])
	{
		(*map)->last_corner[0] = h;
		(*map)->last_corner[1] = h;
	}
	if (h > (*map)->last_corner[1])
		(*map)->last_corner[1] = h;
	if (-1 == (*map)->last_corner[2])
	{
		(*map)->last_corner[2] = w;
		(*map)->last_corner[3] = w;
	}
	if (w < (*map)->last_corner[2])
		(*map)->last_corner[2] = w;
	if (w > (*map)->last_corner[3])
		(*map)->last_corner[3] = w;
}

void	ft_set_piece_corner(t_map **map, int h, int w)
{
	if (-1 == (*map)->piece_corner[0])
	{
		(*map)->piece_corner[0] = h;
		(*map)->piece_corner[1] = h;
	}
	if (h > (*map)->piece_corner[1])
		(*map)->piece_corner[1] = h;
	if (-1 == (*map)->piece_corner[2])
	{
		(*map)->piece_corner[2] = w;
		(*map)->piece_corner[3] = w;
	}
	if (w < (*map)->piece_corner[2])
		(*map)->piece_corner[2] = w;
	if (w > (*map)->piece_corner[3])
		(*map)->piece_corner[3] = w;
}

void	ft_set_shape_corner(t_map **map, int h, int w)
{
	if (-1 == (*map)->shape_corner[0])
	{
		(*map)->shape_corner[0] = h;
		(*map)->shape_corner[1] = h;
	}
	if (h > (*map)->shape_corner[1])
		(*map)->shape_corner[1] = h;
	if (-1 == (*map)->shape_corner[2])
	{
		(*map)->shape_corner[2] = w;
		(*map)->shape_corner[3] = w;
	}
	if (w < (*map)->shape_corner[2])
		(*map)->shape_corner[2] = w;
	if (w > (*map)->shape_corner[3])
		(*map)->shape_corner[3] = w;
}
