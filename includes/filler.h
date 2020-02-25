/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/02/25 18:11:29 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define PLAYER	-2
# define ENEMY	0
# define DOT	-3

typedef struct
{
	int			fd;
	char		player;
	char		enemy;
	int			**map;
	int			map_height;
	int			map_width;
	char		**piece;
	int			piece_height;
	int			piece_width;
	int			piece_set;
	int			piece_min;
	int			piece_h;
	int			piece_w;
}				t_map;

t_map	*ft_init(int fd);
char	*ft_find_line(int fd, char *needle);
void	ft_read_plateau(t_map *map);
void	ft_read_piece(t_map *map);
void	ft_get_size(t_map *map, char *str);
void	ft_heat(t_map *map);
int		ft_put_piece(t_map *map);
void	ft_del_piece(t_map *map);
void	ft_del_map(t_map *map);

#endif
