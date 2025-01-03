/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:52:09 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/03 14:45:25 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

// void	creat_map_array(t_map **map)
// {
// 	int			**array;
// 	t_map_node	*curr;
// 	int	x;
// 	int y;

// 	y = 0;
// 	array = malloc(sizeof(int *) * (*map)->map_y + 1);
// 	curr = (*map)->node;
// 	while (y < (*map)->map_y)
// 	{
// 		x = 0;
// 		array[y] = malloc(sizeof(int) * (*map)->map_x + 1);
// 		while (x <= (*map)->map_x)
// 		{
// 			array[y][x] = curr->z;	
// 			curr = curr->next;
// 			x++;
// 		}
// 		y++;
// 	}
// 	(*map)->array = array;
// }

void	creat_map_array(t_map **map)
{
	t_map_node	***array;
	t_map_node	*curr;
	int	x;
	int y;

	y = 0;
	array = malloc(sizeof(t_map_node **) * (*map)->map_y + 1);
	curr = (*map)->node;
	while (curr->y < (*map)->map_y)
	{
		x = 0;
		array[y] = malloc(sizeof(t_map_node*) * (*map)->map_x + 1);
		while (curr->x <= (*map)->map_x)
		{
			array[y][x] = curr;	
			curr = curr->next;
			x++;
		}
		y++;
	}
	(*map)->nodes = array;
}
