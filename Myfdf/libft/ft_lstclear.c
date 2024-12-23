/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:46:15 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/29 17:37:53 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_list;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp_list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_list;
	}
}
