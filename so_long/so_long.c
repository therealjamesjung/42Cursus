/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:56:54 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/09 19:24:14 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->map_width = 0;
	game->map_height = 0;
	game->player_cnt = 0;
	game->exit_cnt = 0;
	game->pill_cnt = 0;
	game->window = mlx_new_window(game->mlx, 1000, 1000, "mlx 42");
}

void	_end_game(t_game *game)
{
	free(game);
	game = NULL;
	exit(0);
}

int	_validate_width(int map_width, char *tmp)
{
	int	len;

	len = (int) ft_strlen(tmp);
	if (tmp[len - 1] == '\n')
		len--;
	if (len != map_width)
		return (0);
	return (1);
}

void	_validate_map(t_game *game, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (map[i][j] == 'P')
				game->player_cnt++;
			else if (map[i][j] == 'C')
				game->pill_cnt++;
			else if (map[i][j] == 'E')
				game->exit_cnt++;
			if (((i == 0 || i == game->map_height - 1) && map[i][j] != '1') || \
			((j == 0 || j == game->map_width - 1) && map[i][j] != '1'))
			{
				ft_printf("Map must be surrounded by walls.");
				free(map);
				_end_game(game);
			}
		}
	}
}

char	**_init_map(t_game *game, char *file_path)
{
	int		fd;
	char	*map;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	map = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (!game->map_width)
			game->map_width = (int) ft_strlen(tmp) - 1;
		else if (!_validate_width(game->map_width, tmp))
		{
			ft_printf("Invalid map.");
			free(map);
			map = NULL;
			_end_game(game);
		}		
		map = ft_strjoin(map, tmp);
		game->map_height++;
	}
	return (ft_split(map, '\n'));
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	**map;

	if (argc != 2)
	{
		ft_printf("Argument count must be 2. ex) ./a.out map.ber");
		return (0);
	}
	game = (t_game *)malloc(sizeof(t_game));
	_init_game(game);
	map = _init_map(game, argv[1]);
	for (int i=0; i<game->map_height; i++)
		ft_printf("%s\n",map[i]);
	ft_printf("height: %d ", game->map_height);
	ft_printf("width: %d\n", game->map_width);
	_validate_map(game, map);
	mlx_loop(game->mlx);
}
