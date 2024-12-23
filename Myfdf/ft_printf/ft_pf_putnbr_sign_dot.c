/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_sign_dot.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:35:46 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:53:06 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_sign_dot(va_list args, size_t numb_char, size_t dot_len)
{
	size_t	count2;
	int		numb;

	numb = va_arg(args, int);
	count2 = count_decimal(numb);
	if (numb >= 0)
		numb_char += ft_pf_putchar('+');
	while (dot_len > count2 && numb > 0)
	{
		numb_char += ft_pf_putchar('0');
		dot_len--;
	}
	if (numb > 0)
		numb_char += ft_pf_putnbr(numb);
	if (numb < 0)
	{
		numb_char += ft_pf_putnbr_dot(numb, dot_len);
	}
	return (numb_char);
}
