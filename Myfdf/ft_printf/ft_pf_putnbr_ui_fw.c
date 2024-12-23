/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_ui_fw.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:01:40 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 15:30:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_ui_fw(unsigned int n, size_t field_len)
{
	size_t		numb_char;
	char		array[20];
	size_t		i;

	i = 0;
	numb_char = 0;
	if (n == 0)
		array[i++] = 48;
	while (n > 0)
	{
		array[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i < field_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	while (i > 0)
		numb_char += ft_pf_putchar(array[--i]);
	return (numb_char);
}
