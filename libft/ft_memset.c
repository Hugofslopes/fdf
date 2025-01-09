/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:26:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/23 11:46:54 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < n)
		str[i++] = (unsigned char)c;
	return (ptr);
}
