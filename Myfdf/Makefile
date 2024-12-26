# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 10:42:35 by hfilipe-          #+#    #+#              #
#    Updated: 2024/12/26 14:01:45 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
GDB = -ggdb
FLAGS = -Wall -Werror -Wextra
SRC = fdf.c creat_map.c ft_split.c
SRC_GET = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
PRINTF_ARC= ft_printf/libftprintf.a
OBJ = $(SRC:.c=.o)
NAME = fdf
RM = rm -f

all : $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(SRC_GET) $(PRINTF_ARC) -o $(NAME) $(GDB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

