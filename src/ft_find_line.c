/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/02/28 16:02:54 by rgero            ###   ########.fr       */
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