/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_dash_dot_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:41:47 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:23:41 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_dash_dot_u(unsigned int nb, size_t len, size_t field_len)
{
	size_t	numb_char;
	int		i;
	int		array[20];
	int		j;

	i = 0;
	numb_char = 0;
	pf_bzero(array, 20);
	while (nb)
	{
		array[i++] = nb % 10;
		nb /= 10;
	}
	numb_char += ft_pf_dash_dot_ub((size_t)i, len);
	j = i;
	while (i > 0)
		numb_char += ft_pf_putchar(array[--i] + 48);
	numb_char += ft_pf_dash_dot_uc((size_t)j, len, field_len);
	return (numb_char);
}

size_t	ft_pf_dash_dot_ub(size_t i, size_t len)
{
	size_t	number_char;

	number_char = 0;
	while (len > i)
	{
		number_char += ft_pf_putchar('0');
		len--;
	}
	return (number_char);
}

size_t	ft_pf_dash_dot_uc(size_t i, size_t len, size_t field_len)
{
	size_t	number_char;

	number_char = 0;
	if (field_len > i)
	{
		if (field_len > len)
		{
			while (field_len > len && field_len > i)
			{
				number_char += ft_pf_putchar(' ');
				field_len--;
			}
		}
	}
	return (number_char);
}
