/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:17:25 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/01 18:57:37 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	numb_char;
	char	*s;

	numb_char = 0;
	va_start(args, str);
	s = (char *)str;
	while (*s)
	{
		if (*s == '%')
			numb_char += select_formats(args, &s);
		if (*s && *s != '%')
			numb_char += ft_pf_putchar(*s++);
	}
	va_end(args);
	return (numb_char);
}

size_t	select_formats(va_list args, char **format)
{
	size_t	numb_char;

	numb_char = 0;
	(*format)++;
	if (**format == 'c')
		numb_char += ft_pf_putchar(va_arg(args, int));
	else if (**format == 's')
		numb_char += ft_pf_putstr(va_arg(args, char *));
	else if (**format == 'p')
		numb_char += ft_pf_putnbr_p(va_arg(args, unsigned long), BASE_L);
	else if (**format == 'd' || **format == 'i')
		numb_char += ft_pf_putnbr(va_arg(args, int));
	else if (**format == 'u')
		numb_char += ft_pf_putnbr_ui(va_arg(args, unsigned int));
	else if (**format == 'x')
		numb_char += ft_pf_putnbr_hex(va_arg(args, unsigned long), BASE_L);
	else if (**format == 'X')
		numb_char += ft_pf_putnbr_hex(va_arg(args, unsigned long), BASE_U);
	else if (**format == '%')
		numb_char += ft_pf_putchar('%');
	else
		numb_char += analize_flags(args, format, numb_char);
	(*format)++;
	return (numb_char);
}

size_t	analize_flags(va_list args, char **format, size_t numb_char)
{
	while (**format == '#' || **format == '+' || **format == '0' || \
	**format == '-' || **format == '.' || (**format >= '1' && \
	**format <= '9') || **format == ' ')
	{
		if (**format == '#')
			numb_char += hash_flag(args, format, numb_char);
		else if (**format == '+')
			numb_char += put_sign(args, format, numb_char);
		else if (**format == '0')
			numb_char += handle_zero(args, format, numb_char);
		else if (**format == '-')
			numb_char += handle_dash(args, format, numb_char);
		else if (**format == '.')
			numb_char += handle_dot(args, format, numb_char);
		else if (**format == 32)
			numb_char += handle_empty_space(args, format, numb_char);
		else if (**format >= '1' && **format <= '9')
			numb_char += handle_field(args, format, numb_char);
	}
	return (numb_char);
}
