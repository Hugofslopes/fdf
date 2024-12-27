/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bresenhams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:54:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/27 15:12:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenhams(t_map **map)
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	p;

	x = (*map)->node->x;
	y = (*map)->node->y;
	dx = (*map)->node->next->x - (*map)->node->x;
	dy = (*map)->node->next->y - (*map)->node->y;
	p = 2 * dy - dx;
	while (x <= x)
	{
		put_pixel (x, y);
		x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += (2 * dy) - (2 * dx);
			y++;
		}
	}
}
