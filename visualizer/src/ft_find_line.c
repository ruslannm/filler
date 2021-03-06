/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:24:55 by rgero             #+#    #+#             */
/*   Updated: 2020/03/07 14:24:38 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		ft_find_line(char **line, char *needle)
{
	int		ret;
	char	*line_tmp;

	ret = get_next_line(0, &line_tmp);
	while (1 == ret)
	{
		if (-1 == ret)
			break ;
		if (ft_strstr(line_tmp, "=="))
			break ;
		if (ft_strstr(line_tmp, needle))
			break ;
		ft_strdel(&line_tmp);
		ret = get_next_line(0, &line_tmp);
	}
	*line = line_tmp;
	return (ret);
}

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_min(int a, int b)
{
	return (a < b ? a : b);
}
