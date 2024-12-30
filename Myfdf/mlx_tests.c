/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 10:12:13 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/30 16:43:18 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

	void	*mlx;
	void	*window;

int	key_win2(int key,void *p)
{
	printf("Key in Win2 : %d\n",key);
		if (key==0xFF1B)
		{
			exit(0);
		}
}

int draw()
{
	int i = 100;
	while (i < 200)
	{
	mlx_pixel_put(mlx, window, 100, i++, 0xFFFFFF);
	}
	i = 100;
	while (i < 150)
	{
	mlx_pixel_put(mlx, window, i++, 150, 0xFFFFFF);
	}
	i = 100;
	while (i < 200)
	{
	mlx_pixel_put(mlx, window, 150, i++, 0xFFFFFF);
	}
}

void mlx_test(char *av, t_map **map)
{
	int			with;
	int			height;
	t_window	*w;
	int		color_z;
	t_map_node	*maps;

	print_table(map);
	w = malloc(sizeof(t_window) * 1);
		
	(*map)->window = *w;
	with = 1024;
	height = 1080;
	
	if (!((*w).mlx = mlx_init()))
    {
		printf(" !! KO !!\n");
		exit(1);
    }

	if (!((*w).window = mlx_new_window((*w).mlx, height, with, av)))
    {
		printf(" !! KO !!\n");
		exit(1);
    }
	(*map)->window = *w;
	mlx_string_put((*w).mlx, (*w).window, 200, 200, 0x00FFFF, "ISTO E UM TESTE");
	mlx_key_hook((*w).window, key_win2, (*w).window);
	//draw();
	get_zmax(map);
	maps = (*map)->node;
	while (maps->next != NULL)
	{
		color_z = (MAX_COLOR * maps->z) / (*map)->z_max;  
		mlx_pixel_put((*w).mlx, (*w).window, maps->x ,maps->y , color_z);
		maps = maps->next;
	}

	mlx_loop((*w).mlx);
}