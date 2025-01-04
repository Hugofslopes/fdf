# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 10:42:35 by hfilipe-          #+#    #+#              #
#    Updated: 2025/01/04 14:56:21 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
GDB = -ggdb
FLAGS = -Wall -Werror -Wextra -fPIE
SRC = fdf.c creat_map.c creat_map_utils.c frees.c get_rgb.c zoom_center.c\
init.c draw.c max.c
SRC_GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
LIBFT_ARC= libft/libft.a
MLX_ARC= $(MLX_DIR)/libmlx.a
LIBFT_DIR= libft
MLX_DIR= ./mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
OBJ = $(SRC:.c=.o)
NAME = fdf
RM = rm -f

all : $(LIBFT) $(MLX_ARC) $(NAME)

$(MLX_ARC):
		@if [ ! -d "$(MLX_DIR)" ]; then \
			git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
		fi
		@$(MAKE) -C $(MLX_DIR)

$(LIBFT_ARC):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_ARC) $(MLX_ARC)
	$(CC) $(CFLAGS) $(SRC) $(SRC_GET) $(MLX_FLAGS) $(LIBFT_ARC) $(MLX_ARC) \
	-o $(NAME) $(GDB)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE)  $(MLX_DIR)

re: fclean all

