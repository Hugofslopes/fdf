/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_fw_dot_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:50:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 14:49:40 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_fw_dot_hex(unsigned int n, size_t len, size_t field_len, \
char *base)
{
	size_t	numb_char;
	size_t	i;
	int		array[8];

	i = 0;
	numb_char = 0;
	pf_bzero(array, 8);
	while (n && i <= 7)
	{
		array[i++] = n % 16;
		n /= 16;
	}
	if (len > i)
		numb_char += len_is_big(field_len, len, i);
	else
	{
		while (field_len > i)
		{
			numb_char += ft_pf_putchar(' ');
			field_len--;
		}
	}
	while (i > 0)
		numb_char += ft_pf_putchar(base[array[--i]]);
	return (numb_char);
}

size_t	len_is_big(size_t field_len, size_t len, size_t i)
{
	size_t	numb_char;

	numb_char = 0;
	while (field_len > len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len --;
	}
	while (len > i)
	{
		numb_char += ft_pf_putchar('0');
		len--;
	}
	return (numb_char);
}
