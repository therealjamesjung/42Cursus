/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:25 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 20:00:47 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if ((i == 0 || i == game->map_height - 1) && game->map[i][j] != '1')
				_end_game(game, "Error\nMap must be surrounded by walls.");
			if ((j == 0 || j == game->map_width - 1) && game->map[i][j] != '1')
				_end_game(game, "Error\nMap must be surrounded by walls.");
		}
	}
	if (game->player_cnt != 1)
		_end_game(game, "Error\nInvalid player count");
	if (game->exit_cnt != 1)
		_end_game(game, "Error\nInvalid exit count");
}

void	_init_map(t_game *game, char *file_path)
{
	int		fd;
	char	*input_map;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		_end_game(game, "Error\nInvalid input file");
	input_map = (char *)malloc(sizeof(char) * 10000000);
	read(fd, input_map, 10000000);
	game->map_height = _count_char(input_map, '\n') + 1;
	game->map = ft_split(input_map, '\n');
	_validate_width(game);
	ft_printf("%d %d\n", game->map_height, game->map_width);
	ft_printf("%s", input_map);
	_free_input(input_map, fd);
}

void	_set_player(t_game *game, t_image *image, int x, int y)
{
	if (game->direction == 'U')
		_set_image(game, image->back, x, y);
	if (game->direction == 'D')
		_set_image(game, image->front, x, y);
	if (game->direction == 'L')
		_set_image(game, image->left, x, y);
	if (game->direction == 'R')
		_set_image(game, image->right, x, y);
}

void	_set_map(t_game *game, t_image *image, int i, int j)
{
	_set_image(game, image->floor, j * 64, i * 64);
	if (game->map[i][j] == 'C')
		_set_image(game, image->pill, j * 64, i * 64);
	else if (game->map[i][j] == 'E')
		_set_image(game, image->door, j * 64, i * 64);
	else if (game->map[i][j] == '1')
		_set_image(game, image->wall, j * 64, i * 64);
	else if (game->map[i][j] == 'P')
		_set_player(game, image, j * 64, i * 64);
	else if (game->map[i][j] != '0')
	{
		free(image);
		_end_game(game, "Error\nMap is not consisted of 0,1,C,E,P");
	}
}

void	_draw_map(t_game *game)
{
	int		i;
	int		j;
	t_image	*image;

	image = (t_image *)malloc(sizeof(t_image));
	_init_image(game, image);
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
			_set_map(game, image, i, j);
	}
	free(image);
	image = 0;
}
