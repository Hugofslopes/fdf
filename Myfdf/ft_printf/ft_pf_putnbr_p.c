/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:47:21 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:25:07 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_p(unsigned long n, char *base)
{
	size_t	numb_char;
	int		array[20];
	size_t	i;

	numb_char = 0;
	if (n == 0)
	{
		ft_pf_putstr("(nil)");
		return (5);
	}
	numb_char += ft_pf_putstr("0x");
	i = 0;
	while (n > 0)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		numb_char += ft_pf_putchar(base[array[--i]]);
	return (numb_char);
}
