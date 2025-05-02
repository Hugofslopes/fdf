# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 10:42:35 by hfilipe-          #+#    #+#              #
#    Updated: 2025/05/02 17:32:35 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
GDB = -pg -ggdb
CFLAGS = -Wall -Werror -Wextra -fPIE 
SRC_FILES = fdf.c creat_map.c creat_map_utils.c frees.c get_rgb.c zoom_center.c \
	init.c draw.c max.c
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
SRC_GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
LIBFT_ARC = libft/libft.a
MLX_DIR = mlx
MLX_ARC = $(MLX_DIR)/libmlx.a
LIBFT_DIR = libft
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
NAME = fdf
RM = rm -f
DEPS = $(OBJ:.o=.d)

all: $(OBJ_DIR) $(LIBFT_ARC) $(MLX_ARC) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_ARC):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi
	@$(MAKE) -C $(MLX_DIR)

$(LIBFT_ARC):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_ARC) $(MLX_ARC)
	$(CC) $(CFLAGS) $(OBJ) $(SRC_GET) $(MLX_FLAGS) $(LIBFT_ARC) -o $(NAME) $(GDB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

-include $(DEPS)

clean:
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all