/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:56:54 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/18 16:02:15 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_validate_extension(char *file)
{
	if (ft_strncmp(file + (ft_strlen(file) - 4), ".ber", 5))
	{
		ft_printf("Error\nFile extension name must be '.ber'");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nArgument count must be 2. ex) ./a.out map.ber");
		exit(1);
	}
	_validate_extension(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	_init_game(game);
	_init_map(game, argv[1]);
	_validate_map(game);
	game->window = mlx_new_window(game->mlx, \
		64 * game->map_width, 64 * game->map_height, "so_long");
	_draw_map(game);
	mlx_hook(game->window, MLX_EVENT_KEY_PRESS, 0, &_key_event_handler, game);
	mlx_hook(game->window, MLX_EVENT_KEY_EXIT, 0, &_exit_event_handler, game);
	mlx_loop(game->mlx);
}
