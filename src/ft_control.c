/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:50:08 by rgero             #+#    #+#             */
/*   Updated: 2020/03/03 15:35:23 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_fill_line_map(t_map *map, int i, char *str)
{
	int	ret;
	int	k;

	ret = ft_strlen(str);
	ret = (ret == map->map_width + 4 ? 0 : -1);
	k = 4;
	while (k < map->map_width + 4 && 0 == ret)
	{
		if ('.' == str[k])
			map->map[i][k - 4] = DOT;
		else
		{
			if (str[k] == map->enemy)
				map->map[i][k - 4] = ENEMY;
			else if (str[k] == map->enemy + 32)
				map->map[i][k - 4] = LAST;
			else if (str[k] == map->player)
				map->map[i][k - 4] = PLAYER;
			else
				ret = -1;
		}
		k++;
	}
	return (ret);
}

int	ft_control_plateau(t_map **map)
{
	int i;
	int ret;

	ret = 0;
	i = -1;
	while (++i < (*map)->map_height && 0 == ret)
	{
		ret = ft_fill_line_map(*map, i, (*map)->in_map[i]);
	}
	return (ret);
}

