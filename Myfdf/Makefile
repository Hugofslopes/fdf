# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 10:42:35 by hfilipe-          #+#    #+#              #
#    Updated: 2024/12/23 15:04:19 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
GDB = -ggdb
FLAGS = -Wall -Werror -Wextra
SRC = fdf.c creat_map.c
SRC_GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
PRINTF_ARC= ft_printf/libftprintf.a
LIBFT_ARC= libft/libft.a
OBJ = $(SRC:.c=.o)
NAME = fdf
RM = rm -f

all : $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(SRC_GET) $(PRINTF_ARC) $(LIBFT_ARC) -o $(NAME) $(GDB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

