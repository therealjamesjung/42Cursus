# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 14:12:56 by jaekjung          #+#    #+#              #
#    Updated: 2022/06/26 18:39:06 by jaekjung         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = server \
	   client
	   
SERVER_SRCS =	server.c utils.c
CLIENT_SRCS = client.c utils.c
		

SERVER_OBJS = server.o utils.o
CLIENT_OBJS = client.o utils.o
		


LIB_DIR = ./ft_printf
LIB_NAME = libftprintf
LIB = $(LIB_DIR)/$(LIB_NAME).a


all: $(NAME)

bonus: $(BONUS_NAME)

server: $(SERVER_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

client: $(CLIENT_OBJS) $(LIB)
	$(CC) $(CFLAGS) -o $@ $^

	
$(LIB):
	make -C $(LIB_DIR)

clean:
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: fclean all clean re