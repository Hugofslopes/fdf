/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_fw_dot_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:23:09 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 19:44:59 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_fw_dot_s(char *str, size_t len, size_t field_len)
{
	size_t	i;
	size_t	numb_char;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(str);
	numb_char = 0;
	if (!str)
		return (str_null_fw_dot(field_len, numb_char, len));
	if (str_len >= len)
	{
		while (field_len > len)
		{
			numb_char += ft_pf_putchar(' ');
			field_len--;
		}
	}
	else
		ft_pf_fw_dot_sb(numb_char, str_len, field_len);
	while (len && str[i])
	{
		numb_char += ft_pf_putchar(str[i++]);
		len--;
	}
	return (numb_char);
}

size_t	ft_pf_fw_dot_sb(size_t numb_char, size_t str_len, size_t field_len)
{
	while (field_len > str_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}

size_t	str_null_fw_dot(size_t field_len, size_t numb_char, size_t len)
{
	char	*str;

	str = "(null)";
	if (field_len > 6 || field_len > len)
	{
		if (len < 6)
			field_len += len;
		while (field_len > len || field_len > 6)
		{
			numb_char += ft_pf_putchar(' ');
			field_len--;
		}
		if (len > 5)
			numb_char += ft_pf_putstr(str);
	}
	else
	{
		if (len > 5)
			numb_char += ft_pf_putstr(str);
	}
	return (numb_char);
}
