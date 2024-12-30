/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:41:09 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/30 14:41:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	get_x(char ***strgs2, t_map **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (strgs2[x][y])
		y++;
	(*map)->map_x = y - 1;
}

long	ft_atoi_colors(t_map_node **new_node, char *str, char ***strgs2, \
t_map **map)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	if (*str != '-' && *str != '+' && !(*str >= '0' && !*str <= '9'))
		exit_from_atoi(strgs2, map, 1, new_node);
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str != '\0' && *str != ' ' && *str != ',' && *str && *str != '\n')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (*str == ',')
		get_hexa_color(new_node, str, strgs2, map);
	else if (*str != ' ' && *str != '\0' && *str != '\n')
		exit_from_atoi(strgs2, map, 1, new_node);
	else
		standard_color(new_node);
	return (sign * number);
}

void	creat_map_list2(char ***strgs2, t_map **map, int y, int x)
{
	t_map_node	*new_node;
	t_map_node	*curr_node;

	curr_node = (*map)->node;
	new_node = malloc(sizeof(t_map_node) * 1);
	if (!new_node)
	{
		free_strgs2(strgs2);
		ft_lstclear2(&(*map)->node);
		free(map);
		exit (1);
	}
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	new_node->z = (int)ft_atoi_colors(&new_node, strgs2[y][x], strgs2, map);
	if (curr_node == NULL)
		(*map)->node = new_node;
	else
	{
		while (curr_node->next != NULL)
			curr_node = curr_node->next;
		curr_node->next = new_node;
	}
}
