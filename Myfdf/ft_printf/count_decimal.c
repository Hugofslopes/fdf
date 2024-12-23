/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:56:04 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:22:39 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	count_decimal(int nbr)
{
	unsigned int	count;

	count = 0;
	while (nbr)
	{
		count ++;
		nbr /= 10;
	}
	return (count);
}
