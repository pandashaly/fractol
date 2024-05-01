# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssottori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 09:17:44 by ssottori          #+#    #+#              #
#    Updated: 2024/03/27 18:13:56 by ssottori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

NAME = libft.a
CCFLAGS = cc -Wall -Wextra -Werror -g
INC = inc/
AR = ar -rcs
RM = rm -f
OBJ = $(SRCS:.c=.o)

IS = src/ft_is/ft_isalpha.c \
	src/ft_is/ft_isdigit.c \
	src/ft_is/ft_isascii.c \
	src/ft_is/ft_isprint.c \
	src/ft_is/ft_isalnum.c \
	src/ft_is/ft_issign.c \
	src/ft_is/ft_iswhitespace.c \

MEM = src/ft_mem/ft_memset.c \
	src/ft_mem/ft_bzero.c \
	src/ft_mem/ft_memcpy.c \
	src/ft_mem/ft_memmove.c \
	src/ft_mem/ft_calloc.c \
	src/ft_mem/ft_memchr.c \
	src/ft_mem/ft_memcmp.c \

PUT = src/ft_put/ft_putchar_fd.c \
	src/ft_put/ft_putendl_fd.c \
	src/ft_put/ft_putstr_fd.c \
	src/ft_put/ft_putnbr_fd.c \

STR = src/ft_str/ft_split.c \
	src/ft_str/ft_strchr.c \
	src/ft_str/ft_strdup.c \
	src/ft_str/ft_striteri.c \
	src/ft_str/ft_strjoin.c \
	src/ft_str/ft_strlcat.c \
	src/ft_str/ft_strlcpy.c \
	src/ft_str/ft_strlen.c \
	src/ft_str/ft_strmapi.c \
	src/ft_str/ft_strncmp.c \
	src/ft_str/ft_strnstr.c \
	src/ft_str/ft_strrchr.c \
	src/ft_str/ft_strtrim.c \
	src/ft_str/ft_substr.c \
	src/ft_str/ft_strcmp.c \
	src/ft_str/ft_strcpy.c \

LST = src/ft_lst/ft_lstnew.c \
	src/ft_lst/ft_lstadd_front.c \
	src/ft_lst/ft_lstsize.c \
	src/ft_lst/ft_lstlast.c \
	src/ft_lst/ft_lstadd_back.c \
	src/ft_lst/ft_lstdelone.c \
	src/ft_lst/ft_lstclear.c \
	src/ft_lst/ft_lstiter.c \
	src/ft_lst/ft_lstmap.c \

TO = src/ft_to/ft_toupper.c \
	src/ft_to/ft_tolower.c \
	src/ft_to/ft_atoi.c \
	src/ft_to/ft_itoa.c \
	src/ft_to/ft_atol.c \
	src/ft_to/ft_atof.c \

PRINTF = src/ft_printf/ft_printf.c \
	src/ft_printf/utils.c \

GNL = src/ft_gnl/gnl.c \
	src/ft_gnl/gnl_utils.c \

SRCS = $(IS) $(MEM) $(PUT) $(STR) $(LST) $(TO) $(PRINTF) $(GNL)

all: $(NAME)

%.o: %.c $(INC)libft.h $(INC)ft_printf.h $(INC)get_next_line_bonus.h
	@echo "[$(GREEN)LIBFT$(NC)] - $<"
	$(CCFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean: 
	#echo "[$(RED)LIBFT$(NC)] Cleaning up obj files"
	$(RM) $(OBJ) $(OBJ_ADD) $(OBJ_BONUS)

fclean: clean
	#echo "[$(RED)LIBFT$(NC)] Cleaning executable file..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
