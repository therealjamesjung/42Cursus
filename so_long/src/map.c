/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:25 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/18 16:15:18 by jaekjung         ###   ########.fr       */
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
	if (game->player_cnt != 1 || game->exit_cnt != 1 || game->pill_cnt < 1)
		_end_game(game, \
			"Error\nValid map must have 1 player, 1 exit and at least 1 pill");
}

void	_init_map(t_game *game, char *file_path)
{
	int		fd;
	char	*input_map;
	char	*tmp;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		_end_game(game, "Error\nInvalid input file");
	input_map = 0;
	tmp = get_next_line(fd);
	if (!tmp)
		_end_game(game, "Empty File");
	game->map_width = (int) ft_strlen(tmp) - 1;
	while (tmp)
	{	
		if (!_validate_width(game->map_width, tmp))
			_end_game(game, "Error\nInvalid map");
		input_map = _join(input_map, tmp);
		free(tmp);
		tmp = get_next_line(fd);
		game->map_height++;
	}
	game->map = ft_split(input_map, '\n');
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
	char	*move_cnt;

	image = (t_image *)malloc(sizeof(t_image));
	_init_image(game, image);
	i = -1;
	while (++i < game->map_height)
	{
		j = -1;
		while (++j < game->map_width)
			_set_map(game, image, i, j);
	}
	move_cnt = ft_itoa(game->move_cnt);
	mlx_string_put(game->mlx, game->window, 4, 4, 0, move_cnt);
	free(image);
	free(move_cnt);
	image = 0;
	move_cnt = 0;
}
