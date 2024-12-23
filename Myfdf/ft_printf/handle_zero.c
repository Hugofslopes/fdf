/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:40:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 14:45:00 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_zero(va_list args, char **format, size_t numb_char)
{
	size_t	f_len;

	(*format)++;
	f_len = field_size(format);
	if (**format == 's')
		numb_char += ft_pf_putstr_fw(va_arg(args, char *), f_len, numb_char);
	else if (**format == 'd' || **format == 'i')
		numb_char += d_zero(args, numb_char, f_len);
	else if (**format == 'c')
		numb_char += ft_pf_putchar_fw(va_arg(args, int), f_len);
	else if (**format == '.')
		numb_char += analize_dot_fw(args, numb_char, format, f_len);
	else if (**format == 'u')
		numb_char += ft_pf_putnbr_ui_dot(va_arg(args, unsigned int), f_len);
	else if (**format == 'x')
		numb_char += ft_putnbr_hex_dot(va_arg(args, unsigned int), numb_char, \
		f_len, BASE_L);
	else if (**format == 'X')
		numb_char += ft_putnbr_hex_dot(va_arg(args, unsigned int), numb_char, \
		f_len, BASE_U);
	else if (**format == '%')
		numb_char += ft_pf_putchar('%');
	return (numb_char);
}

size_t	d_zero(va_list args, size_t numb_char, size_t f_len)
{
	int	i;

	i = va_arg(args, int);
	if (i > 0)
		numb_char += ft_pf_putnbr_dot(i, f_len);
	else if (i == 0)
	{
		if (f_len == 0)
			numb_char += ft_pf_putchar('0');
		else
		{
			while (f_len)
			{
				numb_char += ft_pf_putchar('0');
				f_len--;
			}
		}
	}
	else
		numb_char += d_zero2(i, numb_char, f_len);
	return (numb_char);
}

size_t	d_zero2(int i, size_t numb_char, size_t f_len)
{
	if (f_len == 0)
		numb_char += ft_pf_putnbr_dot(i, f_len);
	else
		numb_char += ft_pf_putnbr_dot(i, f_len - 1);
	return (numb_char);
}
