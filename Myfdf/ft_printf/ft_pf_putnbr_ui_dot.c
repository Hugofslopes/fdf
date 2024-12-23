/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_ui_dot.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:55:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 18:50:08 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_ui_dot(unsigned int n, size_t field_len)
{
	size_t		numb_char;
	char		array[20];
	size_t		i;

	i = 0;
	numb_char = 0;
	if (n == 0)
		array[i++] = 48;
	if (n == 0 && field_len == 0)
		return (0);
	while (n > 0)
	{
		array[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i < field_len)
	{
		numb_char += ft_pf_putchar('0');
		field_len--;
	}
	while (i > 0)
		numb_char += ft_pf_putchar(array[--i]);
	return (numb_char);
}
