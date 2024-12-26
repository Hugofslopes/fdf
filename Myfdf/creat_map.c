/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/26 14:10:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_fd_size(char *av)
{
	ssize_t	bytesRead;
	int		fd;
	char	buffer[BUFFER_SIZE];
    int		line_count;
	int		i;

	i = 0;
	line_count = 0;
    fd = open(av, O_RDONLY);
    if (fd == -1)
	{
        perror("Error opening file");
        exit (1);
    }
    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) 
	{
		while (i < bytesRead)
		{
            if (buffer[i++] == '\n')
                line_count++;
        }
    }
	close(fd);
	return (line_count);
}

void	creat_str(char *av, char ***strgs, int size)
{
	int	fd;
	int i;
	
	fd = open(av, O_RDONLY);
	i = 0;
	
	while (((*strgs)[i] = get_next_line(fd)) != NULL)
		i++;
	close(fd);
}

void	creat_strgs(char ***strgs, char ****strgs2, int size)
{
	int	j;

	j = 0;
	while (--size >= 0)
	{
		(*strgs2)[j] = ft_split((*strgs)[j], ' ');
		j++;
		size--;
	}
	j = 0;
	while ((*strgs)[j])
	{
		free((*strgs)[j]);
		j++;
	}
	free((*strgs));
}

void free_strgs2 (char ****strgs2)
{
	int			i;
	int			j;
	
	i = 0;
	while ((*strgs2)[i])
	{
		j = 0;
		while ((*strgs2)[i][j])
		{
			free((*strgs2)[i][j]);
			j++;
		}
		free((*strgs2)[i]);
		i++;
	}
	free((*strgs2));
}

void creat_map_list(char ****strgs2, t_map **map)
{
	int			i;
	int			j;
	t_map		*curr;
	t_map_node	*new_node;
	t_map_node	*first_node;
	
	curr = *map;
	first_node = curr->node;
	i = 0;
	while ((*strgs2)[i])
	{
		j = 0;
		while ((*strgs2)[i][j])
		{
			new_node = ft_calloc(sizeof(t_map_node), 1);
			if (!new_node)
				return (free_strgs2);
			new_node = first_node;
			new_node->x = i;
			new_node->y = j;
			new_node->next = NULL;
			new_node->next = ft_atoi_colors(&new_node, (*strgs2)[i][j]);
			j++;
		}
		i++;
	}
	free_strgs2(&strgs2);
}

void	creat_map(char *av, int **array, t_map **map)
{
	char	**strgs;
	char	***strgs2;
	int		fd;
	int		size;

	(*map)->map_y = (get_fd_size(av) * 2);
	size = (*map)->map_y;
	strgs = malloc(sizeof(char *) * size + 1);
	creat_str(av, & strgs, size);
	strgs2 = ft_calloc(sizeof(char **), size + 1);
	creat_strgs(&strgs, &strgs2, size);
	creat_map_list(&strgs2, map);
}
