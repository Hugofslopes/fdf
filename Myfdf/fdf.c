/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:43:30 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/23 16:08:38 by hfilipe-         ###   ########.fr       */
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
		perror("Error: Wrong file name");
		return (0);
	}
	j = 3;
	i--;
	while (j >= 0)
	{
		if (av[i--] != a[j--])
		{
			perror("Error: Wrong format");
			return (0);
		}
	}
	return (1);
}

int	check_ac(int ac)
{
	if (ac < 2)
	{
		perror("Error: Not enough arguments");
		return (0);
	}
	if (ac > 2)
	{
		perror("Error: Too many arguments");
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
	char_readed = read(file, &buffer, 10);
	if (char_readed == 0)
	{
		perror("Error: Empty file");
		return (0);
	}
	close(file);
	return (1);
}

int	main(int ac, char **av)
{
	int	*array;

	// if (!check_inputs(ac, av[1]))
	// 	exit(1);
	creat_map(av[1], &array);
}
