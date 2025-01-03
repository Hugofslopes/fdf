/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:54:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/03 15:58:08 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs (int number)
{
	if (number >= 0)
		return (number);
	else
		return(number * (-1));
}


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


// void slope_less_then_one(int dx, int dy, t_map_node *a, t_map **map)
// 	int p;
// 	int i;

// 	i = 0;
// 	p = 2 * dy - dx;
// 	mlx_pixel_put((*map)->mlx.mlx, (*map)->mlx.window, a->x , a->y ,0xffffff);
// 	while (i < dx)
// 	{
// 		a->x += 1;
// 		if (p < 0)
// 			p = p + 2 * dy;
// 		else	
// 		{
// 			a->y += 1;
// 			p = p + 2 * dy - 2 * dx;
// 		}
// 		mlx_pixel_put((*map)->mlx.mlx, (*map)->mlx.window, a->x , a->y ,0xffffff);
// 		i++;
// 	}
// }
void slope_less_then_one(int dx, int dy, t_map_node *a, t_map **map)
{
	int p;
	int i;

	i = -1;
	p = 2 * ft_abs(dy) - ft_abs(dx);
	while (++i < abs(dx))
	{
		if (dx > 0)
			a->x += 1;
		else
			a->x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if (dy > 0)
				a->y += 1;
			else
				a->y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		mlx_pixel_put((*map)->mlx.mlx, (*map)->mlx.window, a->x , a->y ,0xffffff);
	}
}
void	slope_bigger_than_one(int dx, int dy, t_map_node *a, t_map **map)
{
	int p;
	int i;

	i = -1;
	p = 2 * ft_abs(dx) - ft_abs(dy);
	mlx_pixel_put((*map)->mlx.mlx, (*map)->mlx.window, a->x , a->y ,0xffffff);
	while (++i < dy)
	{
		if (dy > 0)
			a->y += 1;
		else
			a->y -= 1;
		if (p < 0)
			p = p + 2 * ft_abs(dx);
		else
		{
			if (dx > 0)
				a->x += 1;
			else
				a->x -= 1;
			p = p + 2 * abs(dx) - 2 * ft_abs(dy);
		}
		mlx_pixel_put((*map)->mlx.mlx, (*map)->mlx.window, a->x , a->y ,0xffffff);
	}
}

void draw_line(t_map_node *a, t_map_node *b, t_map **map, int check)
{
	float dx;
	float dy;
	float step;
	int i;	
	float x;
	float y;

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
	while(i <= step)
	{
		put_pixel(map, x, y, 0xffffff);
		//mlx_pixel_put((*map)->mlx.mlx, (*map)->mlx.window, x , y ,0xffffff);
		x = x + dx;
		y = y + dy;
		i++;
	}




	// if (check == 1)
	// 	b->x += 1;
	// if (check == 2)
	// 	b->y += 1;
	// dx = b->x - a->x;
	// dy = b->y - a->y;
	// if (ft_abs(dx) > ft_abs(dy))
	// 	slope_less_then_one(dx, dy, a, map);
	// else
	// 	slope_bigger_than_one(dx, dy, a, map);
}

void aply_zoom(t_map **map)
{
	t_map_node *curr;

	curr = (*map)->node;
	while (curr)
	{
		curr->x *= 20;
		curr->y *= 20;
		curr->z *= 20;
		curr = curr->next;
	}
}
void center(t_map **map)
{
	t_map_node *curr;

	curr = (*map)->node;
	while (curr)
	{
		curr->y += 240;
		curr->x += 960;
		curr = curr->next;
	}
}

void  isometric(t_map **map)
{
	t_map_node *curr;
	int tmp;

	curr = (*map)->node;
	while (curr)
	{
		tmp = curr->x;
 		curr->x = (tmp - curr->y) * cos(0.523599);
 		curr->y = (tmp + curr->y) * sin(0.523599) - curr->z;
		curr = curr->next;
	}

	// while (curr)
	// {
	// 	tmp = curr->x;
 	// 	curr->x = curr->x * cos(0.523599) + curr->y * cos(0.523599 + 2) + curr->z * cos(0.523599 - 2);
 	// 	curr->y = curr->x * sin(0.523599) + curr->y * sin(0.523599 + 2) + curr->z * sin(0.523599 - 2);
	// 	curr = curr->next;
	// }
}

void draw_map(t_map **map)
{
	int  x;
	int  y;
	t_map_node *curr;

	aply_zoom(map);
	isometric(map);
	center(map);
	curr = (*map)->node;
	y = 0;
	while (y < (*map)->map_y)
	{
		x = 0;
		while (x < (*map)->map_x)
		{
			// if (x <= (*map)->map_x)
			// {
			draw_line(curr, curr->next, map, 1);
			// }
			// if (y <= (*map)->map_y)
			// {
			// 	draw_line(curr, curr->next, map, 2);
			// }
			x++;
			curr = curr->next;
		}
		y++;
	}
}

//image.img = mlx_new_image(mlx, 1920, 1080);