/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:57:32 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 17:54:35 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_validate_width(int map_width, char *tmp)
{
	int	len;

	len = (int) ft_strlen(tmp);
	if (tmp[len - 1] == '\n')
		len--;
	if (len != map_width)
		return (0);
	return (1);
}

t_point	_init_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	_free_input(char *input, int fd)
{
	free(input);
	input = 0;
	close(fd);
}
