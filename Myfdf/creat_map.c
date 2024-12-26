/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/26 22:32:07 by hfilipe-         ###   ########.fr       */
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
	int			x;
	int			y;
	t_map		*curr;
	t_map_node	*curr_node;
	t_map_node	*new_node;
	
	curr_node = (*map)->node;
	x = 0;
	while ((*strgs2)[x])
	{
		y = 0;
		while ((*strgs2)[x][y])
		{
			new_node = ft_calloc(sizeof(t_map_node), 1);
			if (!new_node)
				{
				free_strgs2(strgs2);
				exit (1);
				}
			new_node->x = x;
			new_node->y = y;
			new_node->next = NULL;
			new_node->z = (int)ft_atoi_colors(&new_node, (*strgs2)[x][y]);
			if ((*map)->node == NULL)
				(*map)->node = new_node;
			else
			{
				curr_node = (*map)->node;
				while (curr_node->next != NULL)
					curr_node = curr_node->next;
				curr_node->next = new_node;	
			}
			ft_printf("X: %5d  ",new_node->x);
			ft_printf("Y: %5d  ",new_node->y);
			ft_printf("Z: %5d  ",new_node->z);
			ft_printf("C: %5d  ",new_node->color);
			y++;
		}
		ft_printf("\n");
		ft_printf("\n");
		x++;
	}
	free_strgs2(strgs2);
}
void	ft_lstclear2(t_map_node **lst)
{
	t_map_node	*tmp;
	t_map_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free (tmp);
	}
	*lst = NULL;
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
	strgs2 = malloc(sizeof(char **) * size + 1);
	creat_strgs(&strgs, &strgs2, size);
	creat_map_list(&strgs2, map);
	ft_lstclear2(&(*map)->node);
	free (map);

}
