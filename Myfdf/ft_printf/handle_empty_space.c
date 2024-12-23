/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_empty_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:59:40 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 19:46:11 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_empty_space(va_list args, char **format, size_t numb_char)
{
	(*format)++;
	if (**format >= '1' && **format <= '9')
		numb_char += handle_field(args, format, numb_char);
	else if (**format == '0')
		numb_char += handle_zero(args, format, numb_char);
	else if (**format == 'd' || **format == 'i')
		numb_char += ft_pf_putnbr_empty(va_arg(args, int));
	else if (**format == 's')
		numb_char += ft_pf_putstr(va_arg(args, char *));
	return (numb_char);
}
