/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_hash_hex_dash.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:42:15 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:52:46 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_hash_hex_dash(unsigned int n, char *base, \
size_t field_len, char c)
{
	size_t	numb_char;
	int		array[11];
	size_t	i;
	size_t	j;
	char	str[10];

	j = 0;
	numb_char = 0;
	pf_bzero(array, 11);
	pf_bzero(str, 10);
	i = 0;
	while (n > 0 && i <= 7)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		str[j++] = base[array[--i]];
	numb_char += ft_pf_putnbr_hash_hex_dashb(str, field_len, c);
	return (numb_char);
}

size_t	ft_pf_putnbr_hash_hex_dashb(char *str, size_t field_len, char c)
{
	size_t	numb_char;
	size_t	len;

	numb_char = 0;
	len = ft_strlen(str);
	if (c == 'l')
		numb_char += ft_pf_putstr("0x");
	else
		numb_char += ft_pf_putstr("0X");
	numb_char += ft_pf_putstr(str);
	while (len < field_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}
