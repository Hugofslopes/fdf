/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_dash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:43:17 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/30 10:02:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_dash(int n, size_t field_len)
{
	long int	numb;
	char		array[20];
	size_t		i;
	size_t		numb_char;

	numb_char = 0;
	numb = n;
	i = 0;
	pf_bzero(array, 20);
	if (numb < 0)
		numb = -numb;
	if (numb == 0)
		array[i++] = 48;
	while (numb > 0)
	{
		array[i++] = (numb % 10) + '0';
		numb /= 10;
	}
	numb_char += ft_pf_putnbr_dash2(n, field_len, i, array);
	return (numb_char);
}

size_t	ft_pf_putnbr_dash2(int n, size_t field_len, size_t i, char *array)
{
	size_t	numb_char;
	size_t	len;

	numb_char = 0;
	len = ft_strlen(array);
	if (n < 0)
		numb_char += ft_pf_putchar('-');
	while (i > 0)
		numb_char += ft_pf_putchar(array[--i]);
	if (n < 0)
		len++;
	while (field_len > (size_t)len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	return (numb_char);
}
