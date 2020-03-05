/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/05 18:34:17 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

char	*ft_find_line1(int fd, char *needle)
{
	char	*ret;

	ret = NULL;
	while (get_next_line(fd, &ret))
	{
		if (!ret)
			return (ret);
		//ft_putstr(ret);
		if (ft_strstr(ret, needle))
			break ;
		ft_strdel(&ret);
	}
	return (ret);
}

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}
