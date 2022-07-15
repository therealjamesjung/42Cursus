/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:58:37 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 17:54:47 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->map = 0;
	game->window = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->player_cnt = 0;
	game->exit_cnt = 0;
	game->pill_cnt = 0;
	game->move_cnt = 0;
	game->direction = 'D';
}

void	_end_game(t_game *game, char *message)
{
	int	i;

	ft_printf("%s\n", message);
	i = -1;
	if (game->map)
	{
		while (++i < game->map_height)
			free(game->map[i]);
		free(game->map);
	}
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	exit(0);
}
