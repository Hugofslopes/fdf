/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:28:20 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/30 16:45:46 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_table(t_map **map)
{
	t_map_node	*maps;
	int i = 0;

	maps = (*map)->node;
	while (maps)
	{	
		if (maps->y == i)
			printf ("X%d Y%d Z%d |",maps->x, maps->y, maps->z);
			//printf ("Z%d ", maps->z);
		else
		{
			i++;
			printf("\n%d\n", i);
			//printf ("Z%d ", maps->z);
			printf ("X%d Y%d Z%d |",maps->x, maps->y, maps->z);
		}
		maps = maps->next;
	}
}


void get_zmax(t_map **map)
{
	int		max_z;
	t_map_node	*maps;

	max_z = -2147483648;
	maps = (*map)->node;

	while(maps)
	{
		if (max_z < maps->z)
			max_z = maps->z;
		maps = maps->next;
	}
	(*map)->z_max = max_z;
}

void top_view(t_map **map)
{

}
