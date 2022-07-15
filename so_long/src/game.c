/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:58:37 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 13:16:14 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->player_cnt = 0;
	game->exit_cnt = 0;
	game->pill_cnt = 0;
	game->move_cnt = 0;
}

void	_end_game(t_game *game, char *message)
{
	ft_printf("%s\n", message);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	free(game);
	game = NULL;
	exit(0);
}
