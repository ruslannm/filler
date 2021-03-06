/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 18:38:31 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define PLAYER		-2
# define ENEMY		0
# define LAST		-1
# define DOT		-3
# define SHOTS		5

typedef struct
{
	int				fd;
	char			player;
	char			enemy;
	char			**in_map;
	int				**map;
	int				opposite_reach;
	int				opposite_corner[2];
	int				last_corner[4];
	int				piece_corner[4];
	int				shape_corner[4];
	int				map_height;
	int				map_width;
	char			**piece;
	int				piece_height;
	int				piece_width;
	int				piece_set;
	int				piece_min_summa;
	int				piece_min_distance;
	int				piece_min_distance_opposite;
	int				piece_last_distance_opposite;
	int				piece_h;
	int				piece_w;
	int				direction;
}					t_map;

int					ft_init(t_map **map);
int					ft_read_plateau(t_map **map);
int					ft_control_plateau(t_map **map);
int					ft_control_piece(t_map **map);
int					ft_read_piece(t_map **map);
int					ft_get_size_piece(t_map **map);
void				ft_heat(t_map **map);
int					ft_put_piece(t_map **map);
void				ft_del_piece(t_map *map);
void				ft_del_map(t_map *map, int height);
void				ft_ini_last_corner(t_map **map);
void				ft_ini_piece_corner(t_map **map);
void				ft_set_last_corner(t_map **map, int h, int w);
void				ft_set_piece_corner(t_map **map, int h, int w);
void				ft_set_shape_corner(t_map **map, int h, int w);
void				ft_set_opposite_corner(t_map **map, int height, int width);
int					ft_abs(int i);
int					ft_max(int a, int b);
int					ft_get_sum(t_map *map, int h, int w);
int					ft_get_distance(t_map **map, int h, int w);
int					ft_get_distance_opposite(t_map *map);
int					ft_get_sum_max(t_map *map);
void				ft_del_in_map(t_map *map, int height);
void				ft_get_piece_corner(t_map **map, int h, int w);
void				ft_get_last_corner(t_map **map);
void				ft_get_opposite_corner(t_map **map);
void				ft_get_shape_corner(t_map **map);
void				ft_set_piece(t_map **map, int *control, int h, int w);

#endif
