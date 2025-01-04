/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:54:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/04 14:09:35 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_map **map, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		pxl = (*map)->mlx.adress + (y * (*map)->mlx.line_length + x * \
		((*map)->mlx.bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

int	get_color(int x, int y, t_map_node *a, t_map_node *b)
{
	int				red;
	int				green;
	int				blue;
	unsigned int	color;
	float			fraction;

	if (b->x - a->x > b->y - a->y)
		fraction = ((float)x - (float)a->x) / ((float)b->x - (float)a->x);
	else
		fraction = ((float)y - (float)a->y) / ((float)b->y - (float)a->y);
	red = a->rgb_r + (b->rgb_r - a->rgb_r) * fraction;
	green = a->rgb_g + (b->rgb_g - a->rgb_g) * fraction;
	blue = a->rgb_b + (b->rgb_b - a->rgb_b) * fraction;
	color = (red << 16) | (green << 8) | blue;
	return (color);
}

void	draw_line(t_map_node *a, t_map_node *b, t_map **map, int i)
{
	float	dx;
	float	dy;	
	float	step;
	float	x;
	float	y;

	dx = b->x - a->x;
	dy = b->y - a->y;
	if (dx >= dy)
		step = dx;
	else
		step = dy;
	dx = dx / step;
	dy = dy / step;
	x = a->x;
	y = a->y;
	i = 0;
	while (i <= step)
	{
		put_pixel(map, x, y, get_color(x, y, a, b));
		x = x + dx;
		y = y + dy;
		i++;
	}
}

void	draw_map(t_map **map, int i)
{
	int			x;
	int			y;
	t_map_node	*curr;
	int			**array;

	aply_zoom(map);
	curr = (*map)->node;
	y = 0;
	while (y < (*map)->map_y)
	{
		x = 0;
		while (x <= (*map)->map_x)
		{
			if (y == (*map)->map_y - 1 && x == (*map)->map_x)
				break ;
			if (x <= (*map)->map_x)
				draw_line(curr, curr->next, map, i);
			if (y < (*map)->map_y - 1)
				draw_line(curr, find_next_y(curr, map), map, i);
			x++;
			curr = curr->next;
		}
		y++;
	}
	ft_lstclear2(&(*map)->node);
}
