/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:12:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/28 12:06:42 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	void	*mlx;
	void	*window;

int	key_win3(int key,void *p)
{
	if (key == XK_Escape)
		mlx_destroy_window(mlx, window);
}

void mlx_test(char *av)
{
	int		with;
	int		height;

	with = 1024;
	height = 1080;
	
	if (!(mlx = mlx_init()))
    {
		printf(" !! KO !!\n");
		exit(1);
    }

	if (!(window = mlx_new_window(mlx, height, with, av)))
    {
		printf(" !! KO !!\n");
		exit(1);
    }

	mlx_string_put(mlx, window, 10, 10, 0x00FFFF, "ISTO E UM TESTE");
	mlx_key_hook(window, key_win3, 0);
	sleep(100);
	
}