/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstr_dash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:49:58 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 12:42:56 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putstr_dash(char *s, size_t field_len, size_t numb_char)
{
	size_t	str_len;

	if (!s)
		return (str_null_dash(field_len, numb_char));
	numb_char = 0;
	str_len = ft_strlen(s);
	while (*s)
		numb_char += ft_pf_putchar(*s++);
	while (field_len > str_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}

size_t	str_null_dash(size_t field_len, size_t numb_char)
{
	numb_char += ft_pf_putstr("(null)");
	while (field_len > 6)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}
