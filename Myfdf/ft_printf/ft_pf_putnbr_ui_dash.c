/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_ui_dash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:01:40 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:28:31 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_ui_dash(unsigned int n, size_t field_len)
{
	size_t	numb_char;
	char	array[20];
	size_t	i;
	size_t	j;

	i = 0;
	numb_char = 0;
	if (n == 0)
		array[i++] = 48;
	while (n > 0)
	{
		array[i++] = (n % 10) + '0';
		n /= 10;
	}
	j = i;
	while (i > 0)
		numb_char += ft_pf_putchar(array[--i]);
	while (j < field_len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}
