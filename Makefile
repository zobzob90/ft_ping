# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eric <eric@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/21 00:00:00 by ertrigna          #+#    #+#              #
#    Updated: 2026/01/26 12:32:04 by eric             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ping

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I inc

SRCS_DIR	= srcs
SRCS		= $(SRCS_DIR)/main.c \
			  $(SRCS_DIR)/init.c \
			  $(SRCS_DIR)/parsing.c \
			  $(SRCS_DIR)/ping.c \
			  $(SRCS_DIR)/utils.c \
			  $(SRCS_DIR)/icmp.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm
	@echo "✅ ft_ping compiled successfully!"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "🧹 Object files cleaned"

fclean: clean
	rm -f $(NAME)
	@echo "🧹 Binary cleaned"

re: fclean all

.PHONY: all clean fclean re
