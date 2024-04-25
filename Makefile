# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:29:37 by ssottori          #+#    #+#              #
#    Updated: 2024/04/22 16:40:06 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TO DO: add mlx -> use if/else to check for linux or mac

# ==============COLORS=================
MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

# ===============FLAGS=================
CCFLAGS = cc -Wall -Wextra -Werror -g
RM = rm -rf
NAME = fractol

SRC_DIR = src
# OBJ_DIR = obj
INC = inc
LIBFT_PATH = libs/libft
LFLAGS = -L$(LIBFT_PATH) -lft
IFLAGS = -I$(INC) -I$(LIBFT_PATH)/inc
LIBFT = $(LIBFT_PATH)/libft.a

# ================SRCS=================
SRCS = errors.c \
	   events.c \
	   parser.c \
	   mandelbrot.c \
	   fractol.c \
	   utils.c \
	   window.c \

OBJS = $(SRCS:.c=.o)

# ================MLX===================

MLX_PATH = libs/mlx
MLX = $(MLX_PATH)/libmlx.a
IFLAGS += -I$(MLX_PATH)

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
			$(CCFLAGS) $(OBJS) $(MLX) $(IFLAGS) $(LFLAGS) -o $(NAME) -lX11 -lXext -lm
	@echo "[$(GREEN)FRACTOL$(NC)] - $<"

%.o: %.c
#			@mkdir -p $(OBJ_DIR)
	echo "[$(GREEN)FRACTOL$(NC)] - $<"
	$(CCFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "[$(RED)FRACTOL$(NC)] Cleaning object files..."
			$(MAKE) -C $(LIBFT_PATH) clean
			@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)FRACTOL$(NC)] Cleaning executable file..."
			$(MAKE) -C $(LIBFT_PATH) fclean
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
