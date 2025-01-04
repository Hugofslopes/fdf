/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:29:29 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/01/04 14:43:04 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	free_strgs2(char ***strgs2)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (strgs2[i])
	{
		j = 0;
		while (strgs2[i][j])
		{
			free(strgs2[i][j]);
			j++;
		}
		free(strgs2[i]);
		i++;
	}
	free(strgs2);
}

void	free_strgs(char **strgs)
{
	int	j;

	j = 0;
	while (strgs[j])
	{
		free(strgs[j]);
		j++;
	}
	free(strgs);
}

void	clean_and_exit(t_map **map)
{
	mlx_destroy_image((*map)->mlx.mlx, (*map)->mlx.image);
	mlx_destroy_window((*map)->mlx.mlx, (*map)->mlx.window);
	mlx_destroy_display((*map)->mlx.mlx);
	free((*map)->mlx.mlx);
	free((*map));
	exit(0);
}

void	exit_from_atoi(char ***strgs2, t_map **map, int error, \
t_map_node **new_node)
{
	if (error == 1)
		ft_putstr_fd("Error: Wrong input", 2);
	else if (error == 2)
		ft_putstr_fd("Error: Wrong map dimensions", 2);
	else if (error == 3)
		ft_putstr_fd("Error: Wrong color input", 2);
	free_strgs2(strgs2);
	ft_lstclear2(&(*map)->node);
	free((*map));
	if (error != 2)
		free(*new_node);
	exit (1);
}
