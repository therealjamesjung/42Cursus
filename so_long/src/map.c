/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:54:25 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 13:22:43 by jaekjung         ###   ########.fr       */
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
	_validate_map(game);
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
		{
			_set_image(game, image->floor, j * 64, i * 64);
			if (game->map[i][j] == 'C')
				_set_image(game, image->pill, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				_set_image(game, image->door, j * 64, i * 64);
			else if (game->map[i][j] == '1')
				_set_image(game, image->wall, j * 64, i * 64);
			if (game->map[i][j] == 'P')
				_set_image(game, image->front, j * 64, i * 64);
		}
	}
}
