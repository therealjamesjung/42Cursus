# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/20 17:00:59 by jaekjung          #+#    #+#              #
#    Updated: 2022/07/20 17:04:12 by jaekjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRCS =	main.c

OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR = ./libft
LIBFT_NAME = libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME).a


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re:
	make fclean
	make all

.PHONY: fclean all clean re