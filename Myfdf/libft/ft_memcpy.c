/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 20:08:32 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/29 14:37:53 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;

	d = (char *)dst;
	s = (char *)src;
	i = 0;
	if (d == s || n == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	while (i++ < n)
		*d++ = *s++;
	return (dst);
}
