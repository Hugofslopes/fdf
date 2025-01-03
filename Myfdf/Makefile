# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 10:42:35 by hfilipe-          #+#    #+#              #
#    Updated: 2025/01/03 14:01:30 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
GDB = -ggdb
FLAGS = -Wall -Werror -Wextra -fPIE
SRC = fdf.c creat_map.c creat_map_utils.c frees.c get_rgb.c mlx_tests.c top_view.c \
init.c Bresenhams.c creat_map_array.c
SRC_GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
PRINTF_ARC= ft_printf/libftprintf.a
LIBFT_ARC= libft/libft.a
MLX_ARC= mlx/libmlx.a
PRINTF_DIR= ft_printf
LIBFT_DIR= libft
MLX_DIR= mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
OBJ = $(SRC:.c=.o)
NAME = fdf
RM = rm -f

all : $(NAME)

$(NAME): $(OBJ) $(PRINTF_ARC) $(LIBFT_ARC) $(MLX_ARC)
	$(CC) $(CFLAGS) $(SRC) $(SRC_GET) $(PRINTF_ARC) $(MLX_FLAGS) $(LIBFT_ARC) $(MLX_ARC) -o $(NAME) $(GDB)

$(LIBFT_ARC):
	$(MAKE) -C $(LIBFT_DIR)
	
$(PRINTF_ARC):
	$(MAKE) -C $(PRINTF_DIR)

$(MLX_ARC):
	$(MAKE) $(MLX_DIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE)  $(MLX_DIR)

re: fclean all

