/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dash_dot_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:50:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 11:53:47 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_dash_dot_hex(unsigned int n, size_t len, \
size_t field_len, char *base)
{
	size_t	numb_char;
	size_t	i;
	int		j;
	int		array[8];

	i = 0;
	numb_char = 0;
	pf_bzero(array, 8);
	while (n > 0 && i <= 7)
	{
		array[i++] = n % 16;
		n /= 16;
	}
	j = (int)i;
	if (len > i)
		numb_char += len_is_big_dash(len, i);
	while (j)
		numb_char += ft_pf_putchar(base[array[--j]]);
	while (field_len > i && field_len > len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}

size_t	len_is_big_dash(size_t len, size_t i)
{
	size_t	numb_char;

	numb_char = 0;
	while (len > i)
	{
		numb_char += ft_pf_putchar('0');
		len--;
	}
	return (numb_char);
}
