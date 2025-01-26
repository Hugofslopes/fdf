/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:31:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/26 10:49:11 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_close(t_map **map)
{
	clean_and_exit(map);
	exit(0);
	return (0);
}

int	key_pressed(int key, t_map **map)
{
	if (key == 0xFF1B)
	{
		clean_and_exit(map);
		exit(0);
	}
	return (0);
}

void	init_mlx(t_map **map, char *av)
{
	t_mlx	new_mlx;
	int		i;
	void	*mlx;
	void	*window;
	void	*image;

	i = 0;
	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, av);
	image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	new_mlx.adress = mlx_get_data_addr(image, &new_mlx.bits_per_pixel, \
	&new_mlx.line_length, &new_mlx.endian);
	(*map)->mlx = new_mlx;
	(*map)->mlx.mlx = mlx;
	(*map)->mlx.window = window;
	(*map)->mlx.image = image;
	(*map)->mlx.adress = new_mlx.adress;
	draw_map(map, i);
	mlx_put_image_to_window(mlx, window, image, 0, 0);
	mlx_key_hook(window, key_pressed, map);
	mlx_hook(window, 17, 0, mouse_close, map);
	mlx_loop(mlx);
}
