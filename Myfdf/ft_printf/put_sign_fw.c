/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign_fw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:17:51 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:51:57 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_sign_fw(va_list args, size_t numb_char, char **format)
{
	size_t	f_len;

	f_len = field_size(format);
	if (**format == '.')
		numb_char += put_sign_fw_dot(args, numb_char, format, f_len);
	else if (**format == 'd' || **format == 'i')
		numb_char += ft_pf_putnbr_sign_fw(va_arg(args, int), f_len);
	else if (**format == 'u')
		numb_char += ft_pf_putnbr_ui_fw(va_arg(args, unsigned int), f_len);
	return (numb_char);
}
