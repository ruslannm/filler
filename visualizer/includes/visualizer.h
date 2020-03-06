/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/03/06 15:09:24 by rgero            ###   ########.fr       */
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

# define MENU_WIDTH	260
# define BGCOLOR	0x000000
# define MENUCOLOR	0x1A001A
# define P1COLOR	0xFF3A19
# define P2COLOR	0x007F40


typedef	struct		s_in_tab
{
	int				pixel[2];
}					t_in_tab;

typedef	struct		s_tab
{
	float			pixel[4];
}					t_tab;

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
	char			*p1_name;
	char			*p2_name;
	int				p1_point;
	int				p2_point;

}					t_map;

int			ft_init(t_map **map);
int		ft_max(int a, int b);
char	*ft_find_line(int fd, char *needle);

#endif
