# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:00:59 by jaekjung          #+#    #+#              #
#    Updated: 2022/08/03 00:36:18 by jaekjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
CHECKER = checker

SRCS =	src/main.c \
		src/sort.c \
		src/utils/utils.c \
		src/utils/sort_utils.c \
		src/utils/stack_utils.c \
		src/utils/parse_utils.c \
		src/utils/rotate_utils.c \
		src/operation/base.c \
		src/operation/push.c \
		src/operation/rotate.c \
		src/operation/swap.c

CHECKER_SRCS =	src/checker.c \
				src/operation/base.c \
				src/operation/push.c \
				src/operation/rotate.c \
				src/utils/utils.c \
				src/utils/stack_utils.c \
				src/utils/parse_utils.c \
				src/utils/rotate_utils.c \
				src/operation/swap.c \
				lib/gnl/get_next_line.c \
				lib/gnl/get_next_line_utils.c


OBJS = $(SRCS:%.c=%.o)
CHECKER_OBJS = $(CHECKER_SRCS:%.c=%.o)

PRINTF_DIR = ./lib/ft_printf
PRINTF_NAME = libftprintf
PRINTF = $(PRINTF_DIR)/$(PRINTF_NAME).a


LIBFT_DIR = ./lib/libft
LIBFT_NAME = libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME).a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^


bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(PRINTF) $(CHECKER_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(CHECKER_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(CHECKER)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re:
	make fclean
	make all

.PHONY: fclean all clean re