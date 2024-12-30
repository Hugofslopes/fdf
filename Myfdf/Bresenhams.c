/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:54:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/30 16:42:39 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs (int number)
{
	if (number >= 0)
		return (number);
	else
		return(number * - 1);
}

void slope_bigger_than_one(int dx, int dy, t_point *a, t_point *b)
{
	int p;
	int i;

	i = 0;
	p = 2 * dx - dy;
	put_pixel(a->x, a->y);
	while (i < dy)
	{
		a->y += 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			a->x += 1;
			p = p + 2 * dx - 2 * dy;
		}
			put_pixel(a->x, a->y);
		i++;
	}
}

void slope_less_then_one(int dx, int dy, t_point *a, t_point *b)
{
	int p;
	int i;

	i = 0;
	p = 2 * dy - dx;
	put_pixel(a->x, a->y);
	while (i < dx)
	{
		a->x += 1;
		if (p < 0)
			p = p + 2 * dy;
		else
		{
			a->y += 1;
			p = p + 2 * dy - 2 * dx;
		}
		put_pixel(a->x, a->y);
		i++;
	}
}

void	bresenhams(t_map **map)
{
	int dx;
	int dy;
	t_map_node *maps;

	maps = (*map)->node;
	dx = maps->next->x - maps->x;
	dx = maps->next->y - maps->y;
	if (abs(dx) > abs(dy))
		slope_less_then_one(dx, dy);
	else
		slope_bigger_than_one(dx, dy);
}
