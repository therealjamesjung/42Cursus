/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:22:32 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 13:22:44 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	_init_image(t_game *game, t_image *image)
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

void	_set_image(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, image, x, y);
}