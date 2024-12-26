/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:43:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/26 14:03:27 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_map_node
{
	int					y;
	int					x;
	int					z;
	int					color;
	struct s_map_node	*next;
}	t_map_node;

typedef struct map_struct
{
	int			map_y;
	int			map_x;		
	t_map_node	*node;
}	t_map;

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void	creat_map(char *av, int **array, t_map **map);
char	**ft_split(char const *s, char c);

#endif