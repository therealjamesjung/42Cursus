/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:21:01 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/15 17:44:47 by jaekjung         ###   ########.fr       */
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
# define MAX_SIZE 1000000000

# include <fcntl.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_game {
	void	*mlx;
	void	*window;
	char	**map;
	int		map_height;
	int		map_width;
	int		player_cnt;
	int		exit_cnt;
	int		pill_cnt;
	int		move_cnt;
	char	direction;
}	t_game;

typedef struct s_image {
	void	*wall;
	void	*floor;
	void	*pill;
	void	*door;
	void	*left;
	void	*right;
	void	*front;
	void	*back;
}	t_image;

int		_validate_width(int map_width, char *tmp);
t_point	_init_point(int x, int y);
void	_free_input(char *input, int fd);

void	_validate_map(t_game *game);
void	_init_map(t_game *game, char *file_path);
void	_draw_map(t_game *game);

void	_init_image(t_game *game, t_image *image);
void	_set_image(t_game *game, void *image, int x, int y);

void	_init_game(t_game *game);
void	_end_game(t_game *game, char *message);

int		_exit_event_handler(t_game *game);
int		_key_event_handler(int key_code, t_game *game);

void	_move(t_game *game, char direction);
#endif