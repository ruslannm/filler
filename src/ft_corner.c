/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 15:56:25 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	corner[4] - coordinates of  rectangle
*/

void	ft_ini_last_corner(t_map **map)
{
	(*map)->last_corner[0] = -1;
	(*map)->last_corner[1] = -1;
	(*map)->last_corner[2] = -1;
	(*map)->last_corner[3] = -1;
}

void	ft_ini_piece_corner(t_map **map)
{
	(*map)->piece_corner[0] = -1;
	(*map)->piece_corner[1] = -1;
	(*map)->piece_corner[2] = -1;
	(*map)->piece_corner[3] = -1;
}

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
