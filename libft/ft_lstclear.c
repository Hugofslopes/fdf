/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:46:15 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/27 10:55:02 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_l **lst)
{
	t_l	*tmp;
	t_l	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free (tmp);
	}
	*lst = NULL;
}
