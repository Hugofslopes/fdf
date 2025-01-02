/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:31:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/02 21:17:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_pressed(int key, void *p)
{
	printf("Key pressed: %d\n",key);
		if (key == 0xFF1B)
		{
			exit(0);
		}
}

void	init_mlx(t_map **map, char *av)
{
	t_mlx *new_mlx;
	
	new_mlx = malloc(sizeof(t_mlx) * 1);
	
	(*new_mlx).mlx  = mlx_init();
	(*new_mlx).window  = mlx_new_window((*new_mlx).mlx ,WIN_WIDTH , WIN_HEIGHT, av);
	(*map)->mlx = *new_mlx;
	(*map)->mlx.mlx = (*new_mlx).mlx;
	(*map)->mlx.window = (*new_mlx).window;
	draw_map(map);
	mlx_key_hook((*new_mlx).window , key_pressed, (*new_mlx).window );
	mlx_loop((*new_mlx).mlx);
}