/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:43:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/03 15:58:10 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
#include <math.h>


typedef struct s_map_node
{
	int					y;
	int					x;
	int					z;
	int					rgb_r;
	int					rgb_g;
	int					rgb_b;
	struct s_map_node	*next;
}	t_map_node;

typedef struct mlx_struct
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*adress;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
} t_mlx;

typedef struct map_struct
{
	int			map_y;
	int			map_x;
	t_map_node	***nodes;
	int			z_max;
	t_map_node	*node;
	t_mlx		mlx;
}	t_map;

#define MAX_COLOR 0xFFFFFF
#define	WIN_WIDTH 1920
#define WIN_HEIGHT 1080


void	creat_map(char *av, int **array, t_map **map);
void	ft_lstclear2(t_map_node **lst);
void	free_strgs(char **strgs);
void	free_strgs2(char ***strgs2);
void	creat_map_list2(char ***strgs2, t_map **map, int x, int y);
void	exit_from_atoi(char ***strgs2, t_map **map, int error, \
t_map_node **new_node);
void	get_x(char ***strgs2, t_map **map);
void	standard_color(t_map_node **new_node);
void	get_hexa_color(t_map_node **new_node, char *str, char ***strgs2, \
t_map **map);
void	mlx_test(char *av, t_map **map);
void top_view(t_map **map);
void get_zmax(t_map **map);
void draw_map(t_map **map);
void	init_mlx(t_map **map, char *av);
void print_table(t_map **map);
void	creat_map_array(t_map **map);
#endif