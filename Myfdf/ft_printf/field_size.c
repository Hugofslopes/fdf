/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:55:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:22:47 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	field_size(char **format)
{
	char			array[11];
	size_t			i;
	unsigned int	field_len;

	pf_bzero(array, 11);
	i = 0;
	field_len = 0;
	while (**format >= '0' && **format <= '9')
	{
		array[i++] = **format;
		(*format)++;
	}
	field_len = ft_pf_atoi(array);
	return (field_len);
}
