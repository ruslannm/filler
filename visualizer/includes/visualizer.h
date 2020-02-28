/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 17:35:44 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# define HEIGHT		1000
# define WIDTH		1000
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
	t_in_tab		**in_tab;
	t_tab			**tab;
	int				height;
	int				width;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				sl;
	int				endian;

	int				map_height;
	int				map_width;
	char			*p1_name;
	char			*p2_name;
	int				p1_point;
	int				p2_point;

}					t_visualizer;

void				ft_err_exit(char *err);
void				ft_read_argv(t_fdf *data, int argc, char **argv);
int					ft_read(int fd, t_fdf **data, t_list *income, int ret);
void				ft_draw(t_fdf *data);
void				ft_rotate(t_fdf *data);
void				ft_rotate_x(t_fdf *data, int i, int j);
void				ft_rotate_y(t_fdf *data, int i, int j);
void				ft_rotate_z(t_fdf *data, int i, int j);
void				ft_projection(t_fdf *data, float *h, float *w, float z);
void				ft_get_tab(t_fdf *data, int ini);
t_fdf				*ft_data_ini(void);
void				ft_data_delete(t_fdf *data);
void				ft_get_in_tab(t_list *income, t_fdf *data);
void				ft_put_image(t_fdf *data);
void				ft_put_pixel(t_fdf *data, int x, int y, int color);

#endif
