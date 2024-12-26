# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 10:42:35 by hfilipe-          #+#    #+#              #
#    Updated: 2024/12/26 20:05:25 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
GDB = -ggdb
FLAGS = -Wall -Werror -Wextra -fPIE
SRC = fdf.c creat_map.c creat_map_utils.c
SRC_GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
PRINTF_ARC= ft_printf/libftprintf.a
LIBFT_ARC= libft/libft.a
PRINTF_DIR= ft_printf
LIBFT_DIR= libft
OBJ = $(SRC:.c=.o)
NAME = fdf
RM = rm -f

all : $(PRINTF_ARC) $(LIBFT_ARC) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(SRC_GET) $(PRINTF_ARC) $(LIBFT_ARC) -o $(NAME) $(GDB)

$(LIBFT_ARC):
	$(MAKE) -C $(LIBFT_DIR)
	
$(PRINTF_ARC):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

