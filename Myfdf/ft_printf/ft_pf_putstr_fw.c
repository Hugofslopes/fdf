/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstr_fw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:49:58 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/30 13:29:32 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putstr_fw(char *s, size_t field_len, size_t numb_char)
{
	size_t	str_len;

	if (!s)
		return (str_null(field_len));
	numb_char = 0;
	str_len = ft_strlen(s);
	while (field_len > str_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	while (*s)
		numb_char += ft_pf_putchar(*s++);
	return (numb_char);
}

size_t	str_null(size_t field_len)
{
	size_t	fw;

	fw = field_len;
	while (field_len > 6)
	{
		ft_pf_putchar(' ');
		field_len--;
	}
	ft_pf_putstr("(null)");
	if (fw > 6)
		return (fw);
	else
		return (6);
}
