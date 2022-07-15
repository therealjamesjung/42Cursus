/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:59:24 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 17:07:51 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_exit_event_handler(t_game *game)
{
	_end_game(game, "Game ended by user");
	return (0);
}

int	_key_event_handler(int key_code, t_game *game)
{
	if (key_code == KEY_ESCAPE)
		_exit_event_handler(game);
	if (key_code == KEY_W)
		_move(game, 'U');
	if (key_code == KEY_S)
		_move(game, 'D');
	if (key_code == KEY_A)
		_move(game, 'L');
	if (key_code == KEY_D)
		_move(game, 'R');
	return (0);
}
