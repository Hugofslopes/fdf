/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fw_dot.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:16:02 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/03 12:35:16 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_hex_fw_dot(unsigned int n, size_t len, size_t dot_len, char c)
{
	size_t			numb_char;
	int				i;
	int				array[8];

	i = 0;
	numb_char = 0;
	pf_bzero(array, 8);
	if (n > 0)
		len -= 2;
	while (n > 0)
	{
		array[i++] = n % 16;
		n /= 16;
	}
	i--;
	numb_char += ft_putnbr_hex_fw_dotb(i, len, dot_len, c);
	numb_char += ft_putnbr_hex_fw_dotc(i, dot_len, 0);
	numb_char += ft_putnbr_hex_fw_dotd(i, array, 0, c);
	return (numb_char);
}

size_t	ft_putnbr_hex_fw_dotb(int i, size_t len, size_t dot_len, char c)
{
	size_t	numb_char;

	numb_char = 0;
	if (len > dot_len && (int)len - 1 > i)
	{
		while (len > dot_len && (int)len - 1 > i)
		{
			numb_char += ft_pf_putchar(' ');
			len--;
		}
	}
	if (c == 'l')
		numb_char += ft_pf_putstr("0x");
	else
		numb_char += ft_pf_putstr("0X");
	return (numb_char);
}

size_t	ft_putnbr_hex_fw_dotc(int i, size_t dot_len, size_t numb_char)
{
	if ((int)dot_len > i)
	{
		while ((int)dot_len - 1 > i)
		{
			numb_char += ft_pf_putchar('0');
			dot_len--;
		}
	}
	return (numb_char);
}

size_t	ft_putnbr_hex_fw_dotd(int i, int *array, size_t numb_char, char c)
{
	if (c == 'l')
	{
		while (i > -1)
			numb_char += ft_pf_putchar(BASE_L[array[i--]]);
	}
	else
	{
		while (i > -1)
			numb_char += ft_pf_putchar(BASE_U[array[i--]]);
	}
	return (numb_char);
}
