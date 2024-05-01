# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otodd <otodd@student.42london.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 19:29:37 by ssottori          #+#    #+#              #
#    Updated: 2024/05/01 15:25:03 by otodd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TO DO: add mlx -> use if/else to check for linux or mac

# ==============COLORS=================
MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

# ===============FLAGS=================
CCFLAGS = cc -Wall -Wextra -Werror
RM = rm -rf
NAME = fractol

SRC_DIR = src
OBJ_DIR = obj
INC = inc
LIBFT_PATH = libs/libft
LFLAGS = -L$(LIBFT_PATH) -lft
IFLAGS = -I$(INC) -I$(LIBFT_PATH)/inc
LIBFT = $(LIBFT_PATH)/libft.a

# ================SRCS=================
SRCS = 	$(SRC_DIR)/fractol.c \
		$(SRC_DIR)/errors.c \
		$(SRC_DIR)/events.c \
		$(SRC_DIR)/parser.c \
		$(SRC_DIR)/mandelbrot.c \
		$(SRC_DIR)/julia.c \
		$(SRC_DIR)/burning_ship.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/window.c \

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ================MLX===================

MLX_URL = git@github.com:42Paris/minilibx-linux.git
CLONE_DIR_NAME = mlx
MLX_INSTALL_DIR = /libs

MLX_PATH = libs/mlx
MLX = $(MLX_PATH)/libmlx.a
# Check if mlx library is installed
#$(info MLX path: $(MLX))

#ifeq ($(MLX_EXISTS),)
#mlx:
#	@echo "MLX is already installed."
#else
#mlx:
#	@echo "Cloning mlx library..."
#	rm -rf $(CLONE_DIR_NAME)
#	git clone $(MLX_URL) $(MLX_PATH)
#endif
#MLX_PATH = libs/mlx
#MLX = $(MLX_PATH)/libmlx.a
IFLAGS += -I$(MLX_PATH)

# ===============BUILD==================

all: $(MLX) $(LIBFT) $(NAME)

dir:
	@mkdir -p $(OBJ_DIR)

$(MLX): 
	$(MAKE) -C $(MLX_PATH)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CCFLAGS) $(OBJS) $(MLX) $(IFLAGS) $(LFLAGS) -o $(NAME) -lX11 -lXext -lm
	@echo "[$(GREEN)FRACTOL$(NC)] - $<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | dir
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
