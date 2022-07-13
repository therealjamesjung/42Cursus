/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:56:54 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/13 19:52:43 by jaekjung         ###   ########.fr       */
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

void	_validate_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			if (game->map[i][j] == 'P')
				game->player_cnt++;
			else if (game->map[i][j] == 'C')
				game->pill_cnt++;
			else if (game->map[i][j] == 'E')
				game->exit_cnt++;
			if (((i == 0 || i == game->map_height - 1) && game->map[i][j] != '1') || \
			((j == 0 || j == game->map_width - 1) && game->map[i][j] != '1'))
			{
				free(game->map); // TODO free map
				_end_game(game, "Map must be surrounded by walls.");
			}
		}
	}
}

void	_init_map(t_game *game, char *file_path)
{
	int		fd;
	char	*input_map;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	input_map = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		if (!game->map_width)
			game->map_width = (int) ft_strlen(tmp) - 1;
		else if (!_validate_width(game->map_width, tmp))
		{
			free(input_map);
			_end_game(game, "Invalid map.");
		}		
		input_map = ft_strjoin(input_map, tmp);
		game->map_height++;
	}
	game->map = ft_split(input_map, '\n');
}

void _init_image(t_game *game, t_image *image)
{
	int		width_height;
	
	width_height = 64;
	image->wall = mlx_xpm_file_to_image(\
		game->mlx, "./res/wall.xpm", &width_height, &width_height);
	image->floor = mlx_xpm_file_to_image(\
		game->mlx, "./res/floor.xpm", &width_height, &width_height);
	image->pill = mlx_xpm_file_to_image(\
		game->mlx, "./res/pill.xpm", &width_height, &width_height);
	image->door = mlx_xpm_file_to_image(\
		game->mlx, "./res/door.xpm", &width_height, &width_height);
	image->left = mlx_xpm_file_to_image(\
		game->mlx, "./res/left.xpm", &width_height, &width_height);
	image->right = mlx_xpm_file_to_image(\
		game->mlx, "./res/right.xpm", &width_height, &width_height);
	image->front = mlx_xpm_file_to_image(\
		game->mlx, "./res/front.xpm", &width_height, &width_height);
	image->back = mlx_xpm_file_to_image(\
		game->mlx, "./res/back.xpm", &width_height, &width_height);
}

void _draw_map(t_game *game)
{
	int		i;
	int		j;
	t_image	*image;

	game->window = mlx_new_window(game->mlx, 64 * game->map_width, 64 * game->map_height, "so_long");
	image = (t_image *)malloc(sizeof(t_image));
	_init_image(game, image);
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
		{
			mlx_put_image_to_window(game->mlx, game->window, image->floor, j * 64, i * 64);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, image->pill, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, image->door, j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, image->wall, j * 64, i * 64);
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->window, image->front, j * 64, i * 64);
		}
	}
}

int	_exit_event_handler(t_game *game)
{
	_end_game(game, "Game Over.");
	return (0);
}

void	move_d(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	ft_printf("aa");
	while(++i < game->map_height)
	{
		j = -1;
		while(++j < game->map_width)
			if (game->map[i][j] == 'P')
			{
				game->map[i][j] = '0';
				game->map[i][j + 1] = 'P';
				_draw_map(game);
				break;
			}
	}
}

int	_key_event_handler(int key_code, t_game *game)
{
	ft_printf("asdfasdf");
	if (key_code == KEY_ESCAPE)
		_exit_event_handler(game);
	if (key_code == KEY_W)
		;//move_w(game);
	if (key_code == KEY_A)
		;//move_a(game);
	if (key_code == KEY_S)
		;//move_s(game);
	if (key_code == KEY_D)
		move_d(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	_init_game(game);
	if (argc != 2)
		_end_game(game, "Argument count must be 2. ex) ./a.out map.ber");
	_init_map(game, argv[1]);
	_validate_map(game);
	_draw_map(game);
	mlx_hook(game->window, MLX_EVENT_KEY_PRESS, 0, &_key_event_handler, game);
	mlx_hook(game->window, MLX_EVENT_KEY_EXIT, 0, &_exit_event_handler, game);
	mlx_loop(game->mlx);
}
