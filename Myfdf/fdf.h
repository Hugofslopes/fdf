/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:43:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/23 16:08:35 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct linked_list
{
	int					y;
	int					x;
	int					color;
	struct link_list	*next;
}	t_list;

typedef struct map_struct
{
	int		map_y;
	int		map_x;		
	t_list	node;
	int		index;
}	t_map;



# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

void	creat_map(char *av, int **array);

#endif