/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:21:01 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/09 19:16:05 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct s_point {
	int x;
	int y;
} t_point;

typedef struct s_game {
	void *mlx;
	void *window;
	int map_height;
	int map_width;
	int player_cnt;
	int exit_cnt;
	int pill_cnt;
} t_game;

typedef struct s_image {
	void *wall;
	void *space;
	void *coin;
} t_image;

#endif