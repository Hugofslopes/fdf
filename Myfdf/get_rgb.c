/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:49 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/28 09:57:42 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_hexa_color2(char *str, t_map **map, char ***strgs2, \
t_map_node **new_node)
{
	int	i;
	int	result;
	int	digit;

	result = 0;
	i = 0;
	while (i < 2)
	{
		if (ft_isdigit(*str))
			digit = *str - '0';
		else if (*str >= 'a' && *str <= 'f')
			digit = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F')
			digit = *str - 'A' + 10;
		else
			break ;
		if (result > 255)
			exit_from_atoi(strgs2, map, 3, new_node);
		result = result * 16 + digit;
		str++;
		i++;
	}
	if (i != 2)
		exit_from_atoi(strgs2, map, 3, new_node);
	return (result);
}

void	get_hexa_color(t_map_node **new_node, char *str, char ***strgs2, \
t_map **map)
{
	*str++;
	if (*str++ != '0')
		exit_from_atoi(strgs2, map, 3, new_node);
	if (*str++ != 'x')
		exit_from_atoi(strgs2, map, 3, new_node);
	if (!(*str >= 'a' && *str <= 'f' || *str >= 'A' && *str <= 'F' || \
	ft_isdigit(*str)))
		exit_from_atoi(strgs2, map, 3, new_node);
	(*new_node)->rgb_r = get_hexa_color2(str, map, strgs2, new_node);
	*str++;
	*str++;
	if (!(*str >= 'a' && *str <= 'f' || *str >= 'A' && *str <= 'F' || \
	ft_isdigit(*str)))
		exit_from_atoi(strgs2, map, 3, new_node);
	(*new_node)->rgb_g = get_hexa_color2(str, map, strgs2, new_node);
	*str++;
	*str++;
	if (!(*str >= 'a' && *str <= 'f' || *str >= 'A' && *str <= 'F' || \
	ft_isdigit(*str)))
		exit_from_atoi(strgs2, map, 3, new_node);
	(*new_node)->rgb_b = get_hexa_color2(str, map, strgs2, new_node);
	*str++;
	*str++;
	if (*str != '\0' && *str != ' ' && *str != '\n')
		exit_from_atoi(strgs2, map, 3, new_node);
}

void	standard_color(t_map_node **new_node)
{
	(*new_node)->rgb_r = 255;
	(*new_node)->rgb_g = 255;
	(*new_node)->rgb_b = 255;
}
