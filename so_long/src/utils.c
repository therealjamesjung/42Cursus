/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:57:32 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 19:58:57 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_validate_width(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->map_height)
	{
		if (!game->map_width)
			game->map_width = ft_strlen(game->map[i]);
		if (game->map_width != (int) ft_strlen(game->map[i]))
			_end_game(game, "Error\nInvalid map");
	}
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

int		_count_char(char *str, char c)
{
	size_t	index;
	int 	cnt;

	cnt = 0;
	index = -1;
	while (++index < ft_strlen(str))
		if (str[index] == c)
			cnt++;
	return (cnt);
}