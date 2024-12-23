/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:54:16 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/30 13:26:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_dash(va_list args, char **format, size_t nub_ch)
{
	size_t	len;
	size_t	count;

	(*format)++;
	while (**format == '-')
		(*format)++;
	if (**format == '0')
		(*format)++;
	len = ft_pf_atoi(*format);
	count = count_decimal(len);
	go_foward_array(format, count);
	nub_ch += handle_dashb(args, format, nub_ch, len);
	return (nub_ch);
}

size_t	handle_dashb(va_list args, char **format, size_t nb_ch, size_t f_len)
{
	if (**format == 'c')
		nb_ch += ft_pf_putchar_dash(va_arg(args, int), f_len);
	else if (**format == '.')
		nb_ch += handle_dash_dot(args, nb_ch, format, f_len);
	else if (**format == 's')
		nb_ch += ft_pf_putstr_dash(va_arg(args, char *), f_len, nb_ch);
	else if (**format == 'p')
		nb_ch += ft_pf_putnbr_p_dash(va_arg(args, unsigned long), \
		BASE_L, f_len);
	else if (**format == 'd' || **format == 'i')
		nb_ch += ft_pf_putnbr_dash(va_arg(args, int), f_len);
	else if (**format == 'u')
		nb_ch += ft_pf_putnbr_ui_dash(va_arg(args, unsigned int), f_len);
	else if (**format == 'x')
		nb_ch += ft_pf_putnbr_hex_dash(va_arg(args, unsigned long), \
		BASE_L, f_len);
	else if (**format == 'X')
		nb_ch += ft_pf_putnbr_hex_dash(va_arg(args, unsigned long), \
		BASE_U, f_len);
	else if (**format == '%')
		nb_ch += ft_pf_putchar('%');
	return (nb_ch);
}
