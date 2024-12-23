/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:21:04 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:29:45 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_sign(va_list args, char **format, size_t numb_char)
{
	(*format)++;
	if (**format == '0')
		(*format)++;
	if (**format == 'd' || **format == 'i')
		numb_char += put_sign_d(va_arg(args, int), numb_char);
	else if (**format == '.')
		numb_char += put_sign_dot(args, numb_char, format);
	else if (**format >= '1' && **format <= '9')
		numb_char += put_sign_fw(args, numb_char, format);
	else if (**format == 'u')
		numb_char += ft_pf_putnbr_ui(va_arg(args, unsigned int));
	return (numb_char);
}

size_t	put_sign_d(int numb, size_t numb_char)
{
	if (numb >= 0)
	{
		numb_char += ft_pf_putchar('+');
		numb_char += ft_pf_putnbr(numb);
	}
	if (numb < 0)
	{
		numb_char += ft_pf_putnbr(numb);
	}
	return (numb_char);
}
