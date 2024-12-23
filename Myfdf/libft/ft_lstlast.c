/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:27:27 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/10/29 17:37:32 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp_list;

	tmp_list = lst;
	if (!lst)
		return (NULL);
	while (tmp_list->next)
		tmp_list = tmp_list->next;
	return (tmp_list);
}
