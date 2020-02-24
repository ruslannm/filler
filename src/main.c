/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:12:17 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 15:21:30 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



int	main(void)
{
	t_map *map;
	int		fd;

	fd = open("filler2.txt", O_RDONLY);
//	fd = 0;
	map = ft_init(fd);
	while (1)
	{
		ft_read_plateau(map);
		ft_read_piece(map);
//		ft_heat_plateau(map);
//		ft_put_piece(map);
//		ft_del_piece(map);
		if (fd)
		{
			close(fd);
			break ;
		}
	}
//	ft_del_map(map);
//	ft_printf("%d\n", 10);
	return (0);
}