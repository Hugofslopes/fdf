/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:31:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/04 13:41:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center(t_map **map)
{
	t_map_node	*curr;
	int			y_max;
	int			y_min;

	y_max = get_y_max(map);
	y_min = get_y_min(map);
	curr = (*map)->node;
	while (curr)
	{
		if (y_max > 900)
			curr->y += 0;
		else if (y_min < -300)
			curr->y += 600;
		else
			curr->y += 500;
		curr->x += 850;
		curr = curr->next;
	}
}

void	isometric(t_map **map)
{
	t_map_node	*curr;
	int			tmp;

	curr = (*map)->node;
	while (curr)
	{
		tmp = curr->x;
		curr->x = (tmp - curr->y) * cos(0.523599);
		curr->y = (tmp + curr->y) * sin(0.523599) - curr->z;
		curr = curr->next;
	}
	center(map);
}

void	aply_zoom(t_map **map)
{
	t_map_node	*curr;
	int			x;
	int			y;
	int			z;
	float		zoom;

	get_zmax(map);
	x = (*map)->map_x;
	y = (*map)->map_y;
	z = (*map)->map_z;
	zoom = 0.5;
	while ((x * zoom) + (y * zoom) + (z * zoom) < 1000)
		zoom += 0.5;
	curr = (*map)->node;
	while (curr)
	{
		curr->n_x = curr->x;
		curr->x *= zoom;
		curr->n_y = curr->y;
		curr->y *= zoom;
		curr->z *= zoom;
		curr = curr->next;
	}
	isometric(map);
}

t_map_node	*find_next_y(t_map_node *curr, t_map **map)
{
	t_map_node	*new_curr;

	new_curr = curr->next;
	while (new_curr)
	{
		if (!new_curr)
			return (NULL);
		if (new_curr->n_x == curr->n_x)
			break ;
		new_curr = new_curr->next;
	}
	return (new_curr);
}
