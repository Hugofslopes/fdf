/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign_fw_dot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:33:09 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:50:28 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_sign_fw_dot(va_list args, size_t numb_char, char **format, \
size_t f_len)
{
	size_t	dot_len;

	(*format)++;
	dot_len = field_size(format);
	if (**format == 'd' || **format == 'i')
		numb_char += ft_pf_sign_fw_dot(va_arg(args, int), dot_len, \
		f_len, numb_char);
	else if (**format == 'u')
		numb_char += ft_pf_fw_dot_u(va_arg(args, unsigned int), dot_len, f_len);
	return (numb_char);
}
