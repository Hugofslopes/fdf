/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:43:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/27 15:55:24 by hfilipe-         ###   ########.fr       */
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

typedef struct s_map_node
{
	int					y;
	int					x;
	int					z;
	int					RGB_R;
	int					RGB_G;
	int					RGB_B;
	struct s_map_node	*next;
}	t_map_node;

typedef struct map_struct
{
	int			map_y;
	int			map_x;
	int			curr_x;
	int			curr_y;
	int			dx;
	int			dy;
	int			p;	
	t_map_node	*node;
}	t_map;

void	creat_map(char *av, int **array, t_map **map);
void	ft_lstclear2(t_map_node **lst);
void	free_strgs(char **strgs);
void	free_strgs2(char ***strgs2);
void	creat_map_list2(char ***strgs2, t_map **map, int x, int y);
void	exit_from_atoi(char ***strgs2, t_map **map, int error);
void	get_x(char ***strgs2, t_map **map);
void 	standard_color(t_map_node **new_node);
void	get_hexa_color(t_map_node **new_node, char *str, char ***strgs2, \
t_map **map);
#endif