/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:39:49 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/27 16:29:24 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_hexa_color2(char *str, t_map **map, char ***strgs2)
{
	int	i;
	int	result;
	int	base;
	int	digit;

	result = 0;
	base = 16;
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
				exit_from_atoi(strgs2, map, 3);
			result = result * base + digit;
			str++;
			i++;
		}
	return (result);	
}

void	get_hexa_color(t_map_node **new_node, char *str, char ***strgs2, \
t_map **map)
{
	*str++;
	*str++;
	*str++;
	if (!(*str >= 'a' && *str <= 'f' || *str >= 'A' && *str <= 'F' || \
	ft_isdigit(*str)))
		exit_from_atoi(strgs2, map, 3);
	(*new_node)->RGB_R = get_hexa_color2(str, map, strgs2);
	*str++;
	*str++;
	if (!(*str >= 'a' && *str <= 'f' || *str >= 'A' && *str <= 'F' || \
	ft_isdigit(*str)))
		exit_from_atoi(strgs2, map, 3);
	(*new_node)->RGB_G = get_hexa_color2(str, map, strgs2);
	*str++;
	*str++;
	if (!(*str >= 'a' && *str <= 'f' || *str >= 'A' && *str <= 'F' || \
	ft_isdigit(*str)))
		exit_from_atoi(strgs2, map, 3);
	(*new_node)->RGB_B = get_hexa_color2(str, map, strgs2);
	*str++;
	*str++;
	if (*str != '\0' && *str != ' ' && *str != '\n')
		exit_from_atoi(strgs2, map, 3);
}

void standard_color(t_map_node **new_node)
{
	(*new_node)->RGB_R = 255;
	(*new_node)->RGB_G = 255;
	(*new_node)->RGB_B = 255;
}
