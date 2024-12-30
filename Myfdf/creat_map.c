/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/30 15:23:56 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_fd_size(char *av)
{
	size_t	bytes_read;
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		line_count;
	int		i;

	i = 0;
	line_count = 0;
	fd = open(av, O_RDONLY);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		i = 0;
		bytes_read = read(fd, buffer, sizeof(buffer));
		while (i < bytes_read)
		{
			if (buffer[i] == '\n')
				line_count++;
			i++;
		}
	}
	close(fd);
	return (line_count);
}

char	**creat_str(char *av, int size)
{
	int				fd;
	int				i;
	char			**strgs;
	static char		*strgs1;

	strgs = malloc(sizeof(char *) * (size + 1));
	if (!strgs)
		return (NULL);
	fd = open(av, O_RDONLY);
	i = 0;
	while (i <= (size - 1))
	{
		strgs[i] = get_next_line(fd, &strgs1);
		if (!strgs[i])
		{
			free_strgs(strgs);
			free(strgs1);
			return (NULL);
		}
		i++;
	}
	strgs[i] = NULL;
	free(strgs1);
	close(fd);
	return (strgs);
}

char	***creat_strgs(char **strgs, int size)
{
	int		j;
	char	***strgs2;

	j = 0;
	strgs2 = malloc(sizeof(char **) * (size + 1));
	if (!strgs2)
	{
		free_strgs(strgs);
		exit (1);
	}
	while (strgs[j])
	{
		strgs2[j] = ft_split(strgs[j], ' ');
		if (!strgs2[j])
		{	
			free_strgs2(strgs2);
			free_strgs(strgs);
			return (NULL);
		}
		j++;
	}
	strgs2[j] = NULL;
	free_strgs(strgs);
	return (strgs2);
}

void	creat_map_list(char ***strgs2, t_map **map)
{
	int			x;
	int			y;

	y = 0;
	x = 0;
	while (y <= ((*map)->map_y) - 1)
	{
		while (strgs2[y][x])
		{
			if (strgs2[y][x] == NULL)
				break ;
			creat_map_list2(strgs2, map, y, x);
			x++;
		}
		if ((x - 1) != ((*map)->map_x))
			exit_from_atoi(strgs2, map, 2, &(*map)->node);
		y++;
		x = 0;
	}
	free_strgs2(strgs2);
}

void	creat_map(char *av, int **array, t_map **map)
{
	char	**strgs;
	char	***strgs2;
	int		fd;
	int		size;

	(*map)->map_y = (get_fd_size(av));
	size = (*map)->map_y;
	strgs = creat_str(av, size);
	if (!strgs)
	{
		free(map);
		exit (1);
	}
	strgs2 = creat_strgs(strgs, size);
	if (!strgs2)
	{
		free(map);
		exit (1);
	}
	get_x(strgs2, map);
	creat_map_list(strgs2, map);
}
