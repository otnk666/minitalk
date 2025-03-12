# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skomatsu <skomatsu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 19:24:23 by skomatsu          #+#    #+#              #
#    Updated: 2025/03/12 19:24:26 by skomatsu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME1 = server
NAME2 = client

SRCS_DIR = ./srcs
OBJS_DIR = ./objs
MAIN_SRCS = $(SRCS_DIR)/main.c

SRCS_SER = $(SRCS_DIR)/server.c 

SRCS_CLI = $(SRCS_DIR)/client.c

SECU_ERR = $(SRCS_DIR)/error_handle.c

OBJS_SER = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS_SER))
OBJS_CLI = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS_CLI))
OBJS_ERR = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SECU_ERR))
OBJ_CLI += $(OBJ_ERR)
OBJ_SER += $(OBJ_ERR)

CC = cc
CFLG = -Wall -Wextra -Werror
RM = rm -f
INCLUDES = -I./includes 

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS_SER)
	@$(MAKE) -C $(OBJS_DIR) 

$(NAME2): $(OBJS_CLI)

%.o: %.c
	@$(CC) $(CFLG) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS_SER) $(OBJS_CLI) $(OBJS_ERR)

fclean: clean
	@$(RM) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
