/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/03/07 15:53:58 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

# define HEIGHT		1200
# define WIDTH		1100
# define FR_HEIGHT	1000
# define FR_WIDTH	1000
# define MENU_RATIO	20
# define BGCOLOR	0x000000
# define FRCOLOR	0xFFFFFF
# define P1COLOR	0xFF3A19
# define P2COLOR	0x007F40

typedef struct
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;

	int				map_height;
	int				map_width;
	int				frame_height;
	int				frame_width;
	int				frame_x;
	int				frame_y;
	int				frame_ratio;
	char			p1_name[50];
	char			p2_name[50];
	int				finish;
}					t_map;

int					ft_init(t_map **map);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_find_line(char **line, char *needle);
int					ft_put_image(t_map *map);
void				ft_fill_bg(t_map **map);
void				ft_fill_bit(t_map **map, int y, int x, int color);
void				ft_fill_bit_last(t_map **map, int y, int x, int color);
void				ft_fill_bit_menu(t_map **map, int y, int x, int color);
int					ft_read_plateau(t_map **map);
int	ft_key(int key, t_map *map);

#endif
