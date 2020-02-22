/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/02/22 16:15:37 by rgero            ###   ########.fr       */
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


# define HEIGHT		1000
# define WIDTH		1000
# define MENU_WIDTH	260
# define BGCOLOR	0x000000
# define MENUCOLOR	0x1A001A

typedef	struct		s_in_tab
{
	int				pixel[2];
}					t_in_tab;

typedef	struct		s_tab
{
	float			pixel[4];
}					t_tab;

typedef struct		s_fdf
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
	int				case_size;
	int				z_size;
	int				height_shift;
	int				width_shift;
	int				x_angle;
	int				y_angle;
	int				z_angle;
	int				menu;
	int				projection;
}					t_fdf;

#endif
