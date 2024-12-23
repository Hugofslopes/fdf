/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_p_dash.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:45:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 19:51:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_p_dash(unsigned long n, char *base, size_t field_len)
{
	int		array[20];
	size_t	i;
	size_t	j;
	char	str[20];
	size_t	numb_char;

	numb_char = 0;
	pf_bzero(str, 20);
	pf_bzero(array, 20);
	if (n == 0)
		return (p_isnull_dash("(nil)", field_len, numb_char));
	if (field_len > 1)
		field_len -= 2;
	i = 0;
	while (n > 0)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	j = 0;
	while (i > 0)
		str[j++] = base[array[--i]];
	numb_char += ft_pf_putnbr_p_dash2(str, field_len);
	return (numb_char);
}

size_t	ft_pf_putnbr_p_dash2(char *str, size_t field_len)
{
	size_t	numb_char;
	size_t	len;

	numb_char = 0;
	len = ft_strlen(str);
	numb_char += ft_pf_putstr("0x");
	numb_char += ft_pf_putstr(str);
	while (field_len > len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}

size_t	p_isnull_dash(char *str, size_t field_len, size_t numb_char)
{
	numb_char += ft_pf_putstr(str);
	if (field_len > 5)
	{
		while (field_len > 5)
		{
			numb_char += ft_pf_putchar(' ');
			field_len--;
		}
	}
	return (numb_char);
}
