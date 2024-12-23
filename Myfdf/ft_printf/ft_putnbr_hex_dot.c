/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_dot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:33:07 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 10:37:16 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_hex_dot(unsigned int n, size_t numb_char, size_t n_zeros, \
char *base)
{
	int		array[8];
	size_t	i;
	size_t	j;
	size_t	len;
	char	str[9];

	pf_bzero(str, 9);
	j = 0;
	i = 0;
	len = 0;
	while (n > 0)
	{
		array[i++] = (n % 16);
		n /= 16;
	}
	while (i > 0)
		str[j++] = base[array[--i]];
	len = ft_strlen(str);
	while (len < n_zeros)
	{
		numb_char += ft_pf_putchar('0');
		n_zeros--;
	}
	numb_char += ft_pf_putstr(str);
	return (numb_char);
}
