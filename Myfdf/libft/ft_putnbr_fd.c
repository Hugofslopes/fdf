/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:20:03 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/23 11:17:15 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	numb;

	numb = n;
	if (numb < 0)
	{
		ft_putchar_fd('-', fd);
		numb = -numb;
	}
	if (numb > 9)
		ft_putnbr_fd(numb / 10, fd);
	ft_putchar_fd((numb % 10) + 48, fd);
}
