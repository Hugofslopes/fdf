/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_sign_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:53:06 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:45:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_sign_dot(va_list args, size_t numb_char, char **format)
{
	size_t		dot_len;

	(*format)++;
	dot_len = field_size(format);
	if (**format == 'd' || **format == 'i')
		numb_char += ft_pf_putnbr_sign_dot(args, numb_char, dot_len);
	if (**format == 'u')
		numb_char += ft_pf_putnbr_ui_dot(va_arg(args, unsigned int), dot_len);
	return (numb_char);
}
