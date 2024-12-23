/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dot_fw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:28:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:30:04 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	handle_dot_fw(char *str, char **format, size_t numb_char, \
size_t field_len)
{
	size_t	len;

	(*format)++;
	len = ft_pf_atoi(*format);
	while (field_len > (size_t)ft_pf_atoi(*format))
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	if (len > ft_strlen(str))
	{
		while (*str)
			numb_char += ft_pf_putchar(*str++);
	}
	else
	{
		while (len >= 1)
		{
			numb_char += ft_pf_putchar(*str);
			str++;
			len--;
		}
	}
	(*format)++;
	return (numb_char);
}
