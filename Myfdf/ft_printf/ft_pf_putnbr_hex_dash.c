/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_hex_dash.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:50 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 10:38:38 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_hex_dash(unsigned int n, char *base, size_t field_len)
{
	size_t	numb_char;
	int		array[8];
	size_t	i;
	size_t	j;
	char	str[9];

	pf_bzero(str, 9);
	pf_bzero(array, 8);
	j = 0;
	numb_char = 0;
	i = 0;
	if (n == 0 && field_len == 0)
		return (ft_pf_putchar('0'), 1);
	if (n == 0 && field_len > 0)
		return (ft_pf_putnbr_hex_dashc(field_len));
	while (n > 0)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		str[j++] = base[array[--i]];
	numb_char += ft_pf_putnbr_hex_dashb(str, field_len);
	return (numb_char);
}

size_t	ft_pf_putnbr_hex_dashb(char *str, size_t field_len)
{
	size_t	len;
	size_t	numb_char;

	numb_char = 0;
	len = ft_strlen(str);
	numb_char += ft_pf_putstr(str);
	while (field_len > len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}

size_t	ft_pf_putnbr_hex_dashc(size_t field_len)
{
	size_t	numb_char;

	numb_char = 0;
	numb_char += ft_pf_putchar('0');
	field_len--;
	while (field_len > 0)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}
