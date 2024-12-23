/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dash_dot_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:23:09 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 19:47:08 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_dash_dot_s(char *str, size_t len, size_t field_len)
{
	size_t	i;
	size_t	numb_char;
	size_t	len2;

	i = 0;
	numb_char = 0;
	len2 = len;
	if (!str)
		return (str_null_dash_dot(field_len, numb_char, len));
	while (len && str[i])
	{
		numb_char += ft_pf_putchar(str[i++]);
		len--;
	}
	while (field_len > len2 || field_len > ft_strlen(str))
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}

size_t	str_null_dash_dot(size_t field_len, size_t numb_char, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = "(null)";
	if (len < 6)
	{
		while (i + 1 < len)
			numb_char += ft_pf_putchar(str[i++]);
		while (field_len > i)
		{
			numb_char += ft_pf_putchar(' ');
			field_len--;
		}
	}
	else
	{
		numb_char += ft_pf_putstr("(null)");
		while (field_len > 6)
		{
			numb_char += ft_pf_putchar(' ');
			field_len--;
		}
	}
	return (numb_char);
}
