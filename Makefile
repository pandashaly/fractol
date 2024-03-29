# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:29:37 by ssottori          #+#    #+#              #
#    Updated: 2024/03/27 18:45:00 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TO DO: add mlx -> use if/else to check for linux or mac

# ==============COLORS=================
MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

# ===============FLAGS=================
CCFLAGS = cc -Wall -Wextra -Werror -ggdb3
RM = rm -rf
NAME = so_long

SRC_DIR = src
OBJ_DIR = obj
INC = inc
LIBFT_PATH = libs/libft
LFLAGS = -L$(LIBFT_PATH) -lft
IFLAGS = -I$(INC) -I$(LIBFT_PATH)/inc
LIBFT = $(LIBFT_PATH)/libft.a

# ================SRCS=================
SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/utils.c \


OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ================MLX===================

MLX_PATH = libs/mlx
MLX = $(MLX_PATH)/libmlx_Linux.a


UNAME_S := $(uname -s)
ifeq ($(UNAME_S),Linux)
	CCFLAGS += -D LINUX
endif
ifeq ($(UNAME_S),Darwin)
	CCFLAGS += -D OSX
endif

# ===============BUILD==================

all: $(MLX) $(LIBFT) $(NAME)

$(MLX): 
	$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS)
			$(CCFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME)
	@echo "[$(GREEN)SO_LONG$(NC)] - $<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/so_long.h
			@mkdir -p $(OBJ_DIR)
	echo "[$(GREEN)SO_LONG$(NC)] - $<"
	$(CCFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "[$(RED)SO_LONG$(NC)] Cleaning object files..."
			$(MAKE) -C $(LIBFT_PATH) clean
			@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "[$(RED)SO_LONG$(NC)] Cleaning executable file..."
			$(MAKE) -C $(LIBFT_PATH) fclean
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
