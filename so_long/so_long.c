/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:56:54 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/12 17:39:12 by jaekjung         ###   ########.fr       */
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
}

void	_end_game(t_game *game, char *message)
{
	ft_printf("%s\n", message);
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
				free(map); // TODO free map
				_end_game(game, "Map must be surrounded by walls.");
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
			free(map);
			_end_game(game, "Invalid map.");
		}		
		map = ft_strjoin(map, tmp);
		game->map_height++;
	}
	return (ft_split(map, '\n'));
}


void _init_image(t_game *game, t_image *image)
{
	int		width_height;
	
	width_height = 64;
	image->wall = mlx_xpm_file_to_image(\
		game->mlx, "./resources/wall.xpm", &width_height, &width_height);
	image->floor = mlx_xpm_file_to_image(\
		game->mlx, "./resources/floor.xpm", &width_height, &width_height);
	image->pill = mlx_xpm_file_to_image(\
		game->mlx, "./resources/pill.xpm", &width_height, &width_height);
	image->left = mlx_xpm_file_to_image(\
		game->mlx, "./resources/left.xpm", &width_height, &width_height);
	image->right = mlx_xpm_file_to_image(\
		game->mlx, "./resources/right.xpm", &width_height, &width_height);
	image->front = mlx_xpm_file_to_image(\
		game->mlx, "./resources/front.xpm", &width_height, &width_height);
	image->back = mlx_xpm_file_to_image(\
		game->mlx, "./resources/back.xpm", &width_height, &width_height);
}

void _draw_map(t_game *game, char **map)
{
	int		i;
	int		j;
	t_image	*image;

	game->window = mlx_new_window(game->mlx, 64 * game->map_width, 64 * game->map_height, "so_long");
	image = (t_image *)malloc(sizeof(t_image));
	_init_image(game, image);
	i = -1;
	j = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{ // P C E 1 0
			mlx_put_image_to_window(game->mlx, game->window, image->floor, j * 64, i * 64);
			if (map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, image->pill, j * 64, i * 64);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, image->floor, j * 64, i * 64);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, image->wall, j * 64, i * 64);
			if (map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, image->front, j * 64, i * 64);
		}
	}
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
	_draw_map(game, map);
	mlx_loop(game->mlx);
}
