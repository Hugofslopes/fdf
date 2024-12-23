/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_p_fw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:45:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/30 13:29:03 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_p_fw(unsigned long n, char *base, size_t field_len)
{
	int		array[20];
	size_t	i;
	size_t	j;
	char	str[20];
	size_t	numb_char;

	numb_char = 0;
	pf_bzero(&str, 20);
	pf_bzero(&array, 20);
	if (n == 0)
		return (pointer_nill (field_len));
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
	numb_char += ft_pf_putnbr_p_fw3(str, field_len);
	return (numb_char);
}

size_t	pointer_nill(size_t field_len)
{
	size_t	fw;

	fw = field_len;
	if (field_len > 5)
	{
		while (field_len > 5)
		{
			ft_pf_putchar(' ');
			field_len--;
		}
		return (ft_pf_putstr("(nil)"), fw);
	}
	ft_pf_putstr("(nil)");
	return (5);
}

size_t	ft_pf_putnbr_p_fw3(char *str, size_t field_len)
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
	numb_char += ft_pf_putstr("0x");
	numb_char += ft_pf_putstr(str);
	return (numb_char);
}
