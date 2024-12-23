/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_sign_fw.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:09:57 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/02 18:49:56 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putnbr_sign_fw(int n, size_t field_len)
{
	long int	numb;
	char		array[20];
	size_t		i;
	size_t		numb_char;

	pf_bzero(array, 20);
	numb_char = 0;
	numb = n;
	i = 0;
	if (numb < 0)
		numb = -numb;
	if (numb == 0)
		array[i++] = 48;
	while (numb > 0)
	{
		array[i++] = (numb % 10) + '0';
		numb /= 10;
	}
	numb_char += ft_pf_putnbr_sign_fw2(n, field_len, i, array);
	return (numb_char);
}

size_t	ft_pf_putnbr_sign_fw2(int n, size_t field_len, size_t i, char *array)
{
	size_t	numb_char;
	size_t	len;

	numb_char = 0;
	len = ft_strlen(array);
	len++;
	while (field_len > (size_t)len)
	{
		numb_char += ft_pf_putchar(' ');
		field_len--;
	}
	if (n < 0)
		numb_char += ft_pf_putchar('-');
	else
		numb_char += ft_pf_putchar('+');
	while (i > 0)
		numb_char += ft_pf_putchar(array[--i]);
	return (numb_char);
}
