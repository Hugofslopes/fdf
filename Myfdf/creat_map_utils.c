/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:41:09 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/26 22:25:31 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_hexa_color(t_map_node **new_node,char *str)
{
	int	result;
    int	base;
    int	digit;

	result = 0;
	base = 16;
    while (*str)
	{
        if (ft_isdigit(*str))
            digit = *str - '0';
        else if (*str >= 'a' && *str <= 'f')
            digit = *str - 'a' + 10;
        else if (*str >= 'A' && *str <= 'F')
            digit = *str - 'A' + 10;
        else 
            break;
        if (result > (2147483647 - digit) / base)
			exit (1);
        result = result * base + digit;
        str++;
    }
	(*new_node)->z = result;
}

long	ft_atoi_colors(t_map_node **new_node, char *str)
{
	int number;
	int sign;

	number = 0;
	sign = 1;
	if (*str != '-' && *str != '+' && !(*str >= '0' && !*str <= '9'))
	{
		exit (1);
	}
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str != '\0' && *str!= ' ' && *str != ',' && *str)
	{
		number = number * 10 + (*str + '0');
		str++;
	}
	if (*str == ',')
		get_hexa_color(new_node, str);
	else if (*str != ' ' && *str != '\0' && *str != '\n')
		exit (1);
	else
	(*new_node)->color = 0xFF;
	return (sign * number);
}
