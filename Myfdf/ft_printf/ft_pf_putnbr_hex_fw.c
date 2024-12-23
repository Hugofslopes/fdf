/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_hex_fw.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:50 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 19:47:41 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_hex_fw(unsigned int n, char *base, size_t field_len)
{
	size_t	numb_char;
	int		array[8];
	size_t	i;
	size_t	j;
	char	str[8];

	pf_bzero(str, 8);
	pf_bzero(array, 8);
	j = 0;
	numb_char = 0;
	i = 0;
	if (n == 0)
		return (hex_zero_fw(numb_char, field_len));
	while (n > 0 && i <= 7)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		str[j++] = base[array[--i]];
	numb_char += ft_pf_putnbr_hex_fwb(str, field_len);
	return (numb_char);
}

size_t	ft_pf_putnbr_hex_fwb(char *str, size_t field_len)
{
	size_t	len;
	size_t	numb_char;

	numb_char = 0;
	len = ft_strlen(str);
	while (len < field_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	numb_char += ft_pf_putstr(str);
	return (numb_char);
}

size_t	hex_zero_fw(size_t numb_char, size_t field_len)
{
	field_len--;
	while (field_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	numb_char += ft_pf_putchar('0');
	return (numb_char);
}
