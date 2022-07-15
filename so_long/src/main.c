/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:56:54 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 13:02:33 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	_init_game(game);
	if (argc != 2)
		_end_game(game, "Argument count must be 2. ex) ./a.out map.ber");
	_init_map(game, argv[1]);
	game->window = mlx_new_window(game->mlx, 64 * game->map_width, 64 * game->map_height, "so_long");
	_draw_map(game);
	mlx_hook(game->window, MLX_EVENT_KEY_PRESS, 0, &_key_event_handler, game);
	mlx_hook(game->window, MLX_EVENT_KEY_EXIT, 0, &_exit_event_handler, game);
	mlx_loop(game->mlx);
}
