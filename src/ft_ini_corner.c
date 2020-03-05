/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_corner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 17:52:26 by rgero            ###   ########.fr       */
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
