/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:59:24 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 13:10:45 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_exit_event_handler(t_game *game)
{
	_end_game(game, "Game Over.");
	return (0);
}

int	_key_event_handler(int key_code, t_game *game)
{
	if (key_code == KEY_ESCAPE)
		_exit_event_handler(game);
	if (key_code == KEY_W)
		_move_up(game);
	if (key_code == KEY_A)
		_move_left(game);
	if (key_code == KEY_S)
		_move_down(game);
	if (key_code == KEY_D)
		_move_right(game);
	return (0);
}
