/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:08:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:42:49 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_dot(va_list args, char **format, size_t nb_ch)
{
	size_t	len;
	size_t	count;

	(*format)++;
	nb_ch = 0;
	len = ft_pf_atoi(*format);
	if (**format == '0')
	{
		count = 1;
		(*format)++;
	}
	len = ft_pf_atoi(*format);
	count = count_decimal(len);
	go_foward_array(format, count);
	if (**format == 's')
		nb_ch += ft_pf_putstr_dot(args, nb_ch, len);
	else if (**format == 'x')
		nb_ch += ft_putnbr_hex_dot(va_arg(args, unsigned int), nb_ch, \
		len, BASE_L);
	else if (**format == 'X')
		nb_ch += ft_putnbr_hex_dot(va_arg(args, unsigned int), \
		nb_ch, len, BASE_U);
	else
		nb_ch += handle_dot2(args, format, nb_ch, len);
	return (nb_ch);
}

size_t	handle_dot2(va_list args, char **format, size_t nb_ch, size_t len)
{
	nb_ch = 0;
	if (**format == 'i' || **format == 'd')
		nb_ch += ft_pf_putnbr_dot(va_arg(args, int), len);
	else if (**format == 'u')
		nb_ch += ft_pf_putnbr_ui_dot(va_arg(args, unsigned int), len);
	else if (**format == 'c')
		nb_ch += ft_pf_putchar(va_arg(args, int));
	return (nb_ch);
}
