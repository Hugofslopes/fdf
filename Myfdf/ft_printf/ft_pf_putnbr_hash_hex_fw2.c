/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_hash_hex_fw2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:51:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 12:23:48 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_hash_hex_fw2(unsigned int n, char *base, \
size_t field_len, char c)
{
	size_t	numb_char;
	int		array[11];
	size_t	i;
	size_t	j;
	char	str[10];

	j = 0;
	numb_char = 0;
	pf_bzero(&str, 10);
	i = 0;
	while (n > 0 && i <= 7)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		str[j++] = base[array[--i]];
	numb_char += ft_pf_putnbr_hash_hex_fw2b(str, field_len, c);
	return (numb_char);
}

size_t	ft_pf_putnbr_hash_hex_fw2b(char *str, size_t field_len, char c)
{
	size_t	numb_char;
	size_t	len;

	numb_char = 0;
	len = ft_strlen(str);
	while (len < field_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	if (c == 'l')
		numb_char += ft_pf_putstr("0x");
	else
		numb_char += ft_pf_putstr("0X");
	numb_char += ft_pf_putstr(str);
	return (numb_char);
}
