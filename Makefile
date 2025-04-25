# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 19:24:23 by skomatsu          #+#    #+#              #
#    Updated: 2025/04/23 00:56:47 by skomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME1 = server
NAME2 = client

SRCS_DIR = ./srcs
OBJS_DIR = ./objs

SRCS_SER =	$(SRCS_DIR)/server.c \
			$(SRCS_DIR)/error_handler.c \
			
SRCS_CLI =	$(SRCS_DIR)/client.c \
			$(SRCS_DIR)/error_handler.c

OBJS_SER =	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS_SER))
OBJS_CLI = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS_CLI))

CC = cc
CFLG = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -rf

INCLUDES = -I./includes -I./libft/includes
LIBFT = -L./libft -lft


all: $(NAME1) $(NAME2)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLG) $(INCLUDES) -c $< -o $@

$(NAME1): $(OBJS_SER)
	@make -C ./libft
	$(CC) $(OBJS_SER) $(LIBFT) -o $@
	
$(NAME2): $(OBJS_CLI)
	@make -C ./libft
	$(CC) $(OBJS_CLI) $(LIBFT) -o $@

clean:
	@make -C ./libft clean
	@$(RM) $(OBJS_SER) $(OBJS_CLI) $(OBJS_DIR)

fclean: clean
	@make -C ./libft fclean
	@$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
