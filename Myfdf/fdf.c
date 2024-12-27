/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:43:30 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/27 15:51:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_av(char *av)
{
	int		i;
	int		j;
	char	*a;

	a = ".fdf";
	i = 0;
	while (av[i])
		i++;
	if (i < 5)
	{
		ft_putstr_fd("Error: Wrong file name", 2);
		return (0);
	}
	j = 3;
	i--;
	while (j >= 0)
	{
		if (av[i--] != a[j--])
		{
			ft_putstr_fd("Error: Wrong format", 2);
			return (0);
		}
	}
	return (1);
}

int	check_ac(int ac)
{
	if (ac < 2)
	{
		ft_putstr_fd("Error: Not enough arguments", 2);
		return (0);
	}
	if (ac > 2)
	{
		ft_putstr_fd("Error: Too many arguments", 2);
		return (0);
	}
	return (1);
}

int	check_inputs(int ac, char *av)
{
	char	*test;
	int		file;
	int		char_readed;
	char	*buffer;

	if (!check_ac(ac))
		return (0);
	if (!check_av(av))
		return (0);
	file = open(av, O_RDONLY);
	if (file <= 0)
	{
		ft_printf("Error opening file: %s\n", strerror(errno));
		return (0);
	}
	char_readed = read(file, &buffer, 8);
	if (char_readed == 0)
	{
		ft_putstr_fd("Error: Empty file", 2);
		return (0);
	}
	close(file);
	return (1);
}

int	main(int ac, char **av)
{
	int		*array;
	t_map	*map;

	map = malloc(sizeof(t_map) * 1);
	if (!check_inputs(ac, av[1]))
		exit(1);
	map->map_x = 0;
	map->map_y = 0;
	map->node = NULL;
	creat_map(av[1], &array, &map);
	ft_lstclear2(&map->node);
	free(map);
}
