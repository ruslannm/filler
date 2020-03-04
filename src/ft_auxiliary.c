/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/04 17:10:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_find_line(int fd, char *needle)
{
	char	*ret;

	while (get_next_line(fd, &ret))
	{
		if (ft_strstr(ret, needle))
			break ;
		ft_strdel(&ret);
	}
	return (ret);
}

int		ft_abs(int i)
{
	return (i < 0 ? -i : i);
}

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_get_size_piece(t_map **map)
{
	char	*line;
	int		ret;
	char	*height;
	char	*width;

	ret = 0;
	get_next_line((*map)->fd, &line);
	if (ft_strncmp("Piece ", line, 6))
		ret = -1;
	else if (ft_strlen(line) < 10)
		ret = -1;
	else
	{
		height = ft_strchr(line, ' ') + 1;
		width = ft_strrchr(line, ' ') + 1;
		if (ft_isdigit(height[0]) && ft_isdigit(width[0]))
		{
			(*map)->piece_height = ft_atoi(height);
			(*map)->piece_width = ft_atoi(width);
		}
		else
			ret = -1;
	}
	ft_strdel(&line);
	return (ret);
}

void	ft_get_opposite_corner(t_map **map)
{
	
};