/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:02:34 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 13:23:48 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_move_up(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(++i < game->map_height)
	{
		j = -1;
		while(++j < game->map_width)
			if (game->map[i][j] == 'P' && game->map[i - 1][j] != '1')
			{
				game->map[i][j] = '0';
				game->map[i - 1][j] = 'P';
				game->move_cnt++;
				_draw_map(game);
				break;
			}
	}
}

void	_move_down(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(++i < game->map_height)
	{
		j = -1;
		while(++j < game->map_width)
			if (game->map[i][j] == 'P' && game->map[i + 1][j] != '1')
			{
				game->map[i][j] = '0';
				game->map[i + 1][j] = 'P';
				game->move_cnt++;
				_draw_map(game);
				break;
			}
	}
}

void	_move_left(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(++i < game->map_height)
	{
		j = -1;
		while(++j < game->map_width)
			if (game->map[i][j] == 'P' && game->map[i][j - 1] != '1')
			{
				game->map[i][j] = '0';
				game->map[i][j - 1] = 'P';
				game->move_cnt++;
				_draw_map(game);
				break;
			}
	}
}

void	_move_right(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while(++i < game->map_height)
	{
		j = -1;
		while(++j < game->map_width)
			if (game->map[i][j] == 'P' && game->map[i][j + 1] != '1')
			{
				game->map[i][j] = '0';
				game->map[i][j + 1] = 'P';
				game->move_cnt++;
				_draw_map(game);
				break;
			}
	}
}
