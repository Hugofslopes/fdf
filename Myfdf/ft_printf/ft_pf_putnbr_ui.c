/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:32:44 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:28:36 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_ui(unsigned int n)
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
	while (i > 0)
		numb_char += ft_pf_putchar(array[--i]);
	return (numb_char);
}
