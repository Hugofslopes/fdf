/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:31:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/03 15:58:09 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_pressed(int key)
{
	// printf("Key pressed: %d\n",key);
		if (key == 0xFF1B)
		{
			//free..
			exit(0);
		}
}

void	init_mlx(t_map **map, char *av)
{
	t_mlx *new_mlx;
	
	new_mlx = malloc(sizeof(t_mlx) * 1);
	
	(*new_mlx).mlx  = mlx_init();
	(*new_mlx).window  = mlx_new_window((*new_mlx).mlx ,WIN_WIDTH , WIN_HEIGHT, av);
	(*new_mlx).image = mlx_new_image((*new_mlx).mlx, WIN_WIDTH, WIN_HEIGHT);
	(*new_mlx).adress = mlx_get_data_addr((*new_mlx).image, &(*new_mlx).bits_per_pixel, \
	&(*new_mlx).line_length, &(*new_mlx).endian);

	(*map)->mlx = *new_mlx;
	(*map)->mlx.mlx = (*new_mlx).mlx;
	(*map)->mlx.window = (*new_mlx).window;
	(*map)->mlx.image =(*new_mlx).image;
	(*map)->mlx.adress = (*new_mlx).adress ; 
	draw_map(map);
	mlx_put_image_to_window((*new_mlx).mlx, (*new_mlx).window, (*new_mlx).image, 0, 0);
	mlx_key_hook((*new_mlx).window , key_pressed, 0);
	mlx_loop((*new_mlx).mlx);
}
