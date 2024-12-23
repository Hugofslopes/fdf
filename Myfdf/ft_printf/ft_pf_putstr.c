/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:12:21 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:28:18 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_pf_putstr(char *s)
{
	size_t	numb_char;

	numb_char = 0;
	if (!s)
	{
		ft_pf_putstr("(null)");
		return (6);
	}
	while (*s)
		numb_char += ft_pf_putchar(*s++);
	return (numb_char);
}
