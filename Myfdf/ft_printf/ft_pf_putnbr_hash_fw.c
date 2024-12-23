/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_hash_fw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:44:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 14:36:09 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_hash_fw(va_list args, char **format, size_t numb_char)
{
	size_t	len;
	size_t	count;

	numb_char = 0;
	len = ft_pf_atoi(*format);
	count = count_decimal(len);
	go_foward_array(format, count);
	if (len == 0 && (**format != 'x' && **format != 'X' && **format != '.'))
		(*format)++;
	if (**format == '.')
		numb_char += putnbr_hash_fw_dot(va_arg(args, unsigned int), \
		format, numb_char, len);
	else
	{
		if (**format == 'x')
			numb_char += ft_pf_putnbr_hash_hex_fw2(va_arg(args, unsigned int), \
		BASE_L, len - 2, 'l');
		if (**format == 'X')
			numb_char += ft_pf_putnbr_hash_hex_fw2(va_arg(args, unsigned int), \
			BASE_U, len - 2, 'u');
	}
	return (numb_char);
}

size_t	putnbr_hash_fw_dot(unsigned long n, char **format, size_t numb_char, \
size_t len)
{
	size_t	dot_len;
	size_t	count;

	(*format)++;
	numb_char = 0;
	dot_len = ft_pf_atoi(*format);
	count = count_decimal(dot_len);
	go_foward_array(format, count);
	if (dot_len == 0 && (**format != 'x' && **format != 'X'))
		(*format)++;
	if (**format == 'x')
		numb_char += ft_putnbr_hex_fw_dot(n, len, dot_len, 'l');
	if (**format == 'X')
		numb_char += ft_putnbr_hex_fw_dot(n, len, dot_len, 'u');
	return (numb_char);
}
