# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 15:32:01 by jaekjung          #+#    #+#              #
#    Updated: 2022/05/07 14:35:17 by jaekjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS =	ft_printf.c \
		format/print_c.c \
		format/print_i.c \
		format/print_p.c \
		format/print_s.c \
		format/print_x.c \
		format/utils.c
OBJS = $(SRCS:%.c=%.o)
NAME = libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: fclean all clean re
