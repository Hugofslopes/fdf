/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:31:31 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/08 17:35:33 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_zmax(t_map **map)
{
	t_map_node	*curr;
	int			zmax;

	curr = (*map)->node;
	zmax = 0;
	while (curr)
	{
		if (curr->z > zmax)
			zmax = curr->z;
		curr = curr->next;
	}
	(*map)->map_z = zmax;
}

int	get_y_max(t_map **map)
{
	t_map_node	*curr;
	int			y_max;

	y_max = 0;
	curr = (*map)->node;
	while (curr)
	{
		if (curr->y > y_max)
			y_max = curr->y;
		curr = curr->next;
	}
	return (y_max);
}

int	get_y_min(t_map **map)
{
	t_map_node	*curr;
	int			y_min;

	y_min = 2000;
	curr = (*map)->node;
	while (curr)
	{
		if (curr->y < y_min)
			y_min = curr->y;
		curr = curr->next;
	}
	return (y_min);
}

void	get_x(char ***strgs2, t_map **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (strgs2[x][y])
		y++;
	(*map)->map_x = y - 1;
}

int	get_x_line(int y, t_map **map)
{
	t_map_node	*curr;

	curr = (*map)->node;
	while (curr->n_y != y)
		curr = curr->next;
	if (curr->next != NULL)
	{
		while (curr->next && curr->next->n_y == y)
			curr = curr->next;
	}
	return (curr->n_x);
}
