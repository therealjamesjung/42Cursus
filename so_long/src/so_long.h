/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:21:01 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/13 19:52:44 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_EVENT_KEY_PRESS 2
# define MLX_EVENT_KEY_RELEASE 3
# define MLX_EVENT_KEY_EXIT 17
# define KEY_ESCAPE 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# include <fcntl.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"

typedef struct s_point {
	int x;
	int y;
} t_point;

typedef struct s_game {
	void *mlx;
	void *window;
	char **map;
	int map_height;
	int map_width;
	int player_cnt;
	int exit_cnt;
	int pill_cnt;
} t_game;

typedef struct s_image {
	void *wall;
	void *floor;
	void *pill;
	void *door;
	void *left;
	void *right;
	void *front;
	void *back;
} t_image;

#endif