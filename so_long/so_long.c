/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:56:54 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/09 18:05:03 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void _init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 1000, 1000, "mlx 42");
}

char *_init_map(char *file_path)
{
	int	fd;
	char *map;
	char *tmp;

	fd = open(file_path, O_RDONLY);
	map = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		map = ft_strjoin(map, tmp);
		if (!tmp)
			break;
	}
	//_validate_map(map);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*map;

	if (argc != 2)
		ft_printf("Argument count must be 2. ex) ./a.out map.ber");
	map = _init_map(argv[1]);
	ft_printf("%s", map);
	game = (t_game *)malloc(sizeof(t_game));
	_init_game(game);
	mlx_loop(game->mlx);
}