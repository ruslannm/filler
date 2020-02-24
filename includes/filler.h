/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2020/02/24 13:07:26 by rgero            ###   ########.fr       */
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

typedef struct
{
	int		height;
	int		width;
	char	**info;
}			t_object;

typedef struct
{
	int			fd;
	char		player;
	char		enemy;
	t_object	*plateau;
	t_object	*piece;
}				t_map;

t_map	*ft_init(int fd);
char	*ft_find_line(int fd, char *needle);

#endif
