/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:55:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/11/29 17:29:16 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*pf_bzero(void *ptr, size_t n)
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)ptr;
	while (i < n)
		str[i++] = '\0';
	return (str);
}
