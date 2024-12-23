/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:08:59 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 14:47:39 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	hash_flag(va_list args, char **format, size_t numb_char)
{
	(*format)++;
	numb_char = 0;
	if (**format >= '0' && **format <= '9')
		numb_char += ft_pf_putnbr_hash_fw(args, format, numb_char);
	else if (**format == '.')
		numb_char += handle_dot_hash(va_arg(args, unsigned int), format, \
		numb_char);
	else if (**format == '-')
		numb_char += handle_dash_hash(args, format, numb_char);
	else
	{
		numb_char += elses(args, format, numb_char);
	}
	return (numb_char);
}

size_t	elses(va_list args, char **format, size_t numb_char)
{
	unsigned int	i;

	i = va_arg(args, unsigned int);
	if (**format == 'x')
	{
		if (i == 0)
			numb_char += ft_pf_putnbr_hex(i, BASE_L);
		else
		{
			numb_char += ft_pf_putstr("0x");
			numb_char += ft_pf_putnbr_hex(i, BASE_L);
		}
	}
	if (**format == 'X')
	{
		if (i == 0)
			numb_char += ft_pf_putnbr_hex(i, BASE_U);
		else
		{
			numb_char += ft_pf_putstr("0X");
			numb_char += ft_pf_putnbr_hex(i, BASE_U);
		}
	}
	return (numb_char);
}
