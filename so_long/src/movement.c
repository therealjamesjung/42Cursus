/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:02:34 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/18 16:02:30 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_move_player(t_game *game, t_point prev, t_point next)
{
	if (game->map[prev.x][prev.y] == 'P' && game->map[next.x][next.y] != '1')
	{
		if (game->map[next.x][next.y] == 'E')
		{
			if (game->pill_cnt != 0)
			{
				ft_printf("You should collect all pills\n");
				return (0);
			}
			_end_game(game, "Game Over");
		}
		game->move_cnt++;
		if (game->map[next.x][next.y] == 'C')
			game->pill_cnt--;
		game->map[prev.x][prev.y] = '0';
		game->map[next.x][next.y] = 'P';
		_draw_map(game);
		return (1);
	}
	return (0);
}

void	_move(t_game *game, char direction)
{
	t_point	iter;
	t_point	prev;
	t_point	next;

	iter.x = -1;
	while (++iter.x < game->map_height)
	{
		iter.y = -1;
		while (++iter.y < game->map_width)
		{
			prev = _init_point(iter.x, iter.y);
			next = _init_point(iter.x, iter.y);
			game->direction = direction;
			if (direction == 'U')
				next.x = iter.x - 1;
			else if (direction == 'D')
				next.x = iter.x + 1;
			else if (direction == 'L')
				next.y = iter.y - 1;
			else if (direction == 'R')
				next.y = iter.y + 1;
			if (_move_player(game, prev, next))
				return ;
		}	
	}
}
