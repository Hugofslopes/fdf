/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:22:04 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:26:52 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_with(char **format)
{
	size_t	field_len;

	(*format)++;
	field_len = 0;
	if (**format >= '1' && **format <= '9')
		field_len = field_size(format);
	if (field_len > 0)
		return (field_len);
	else
		return (0);
}
