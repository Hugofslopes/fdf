/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dot_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:08:59 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 13:49:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_dot_hash(unsigned int nbr, char **format, size_t numb_char)
{
	size_t	len;
	size_t	count;

	(*format)++;
	len = ft_pf_atoi(*format);
	count = count_decimal(len);
	go_foward_array(format, count);
	if (**format == 'x')
	{
		numb_char += ft_pf_putstr("0x");
		numb_char += ft_putnbr_hex_dot(nbr, numb_char, len, BASE_L);
	}
	if (**format == 'X')
	{
		numb_char += ft_pf_putstr("0x");
		numb_char += ft_putnbr_hex_dot(nbr, numb_char, len, BASE_U);
	}
	return (numb_char);
}
