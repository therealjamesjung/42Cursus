# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/09 17:42:48 by jaekjung          #+#    #+#              #
#    Updated: 2022/07/18 16:08:33 by jaekjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX = -lmlx -framework OpenGL -framework Appkit

NAME = so_long

SRCS =	src/main.c \
		src/event.c \
		src/game.c \
		src/map.c \
		src/image.c \
		src/movement.c \
		src/utils.c \
		lib/gnl/get_next_line.c \
		lib/gnl/get_next_line_utils.c \

OBJS = $(SRCS:%.c=%.o)

PRINTF_DIR = ./lib/ft_printf
PRINTF_NAME = libftprintf
PRINTF = $(PRINTF_DIR)/$(PRINTF_NAME).a


LIBFT_DIR = ./lib/libft
LIBFT_NAME = libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME).a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(MLX) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:
	make fclean
	make all

.PHONY: fclean all clean re