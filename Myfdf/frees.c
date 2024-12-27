/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:29:29 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/27 12:10:01 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_lstclear2(t_map_node **lst)
{
	t_map_node	*tmp;
	t_map_node	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		tmp = curr;
		curr = curr->next;
		free (tmp);
	}
	*lst = NULL;
}

void	free_strgs2(char ***strgs2)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (strgs2[i])
	{
		j = 0;
		while (strgs2[i][j])
		{
			free(strgs2[i][j]);
			j++;
		}
		free(strgs2[i]);
		i++;
	}
	free(strgs2);
}

void	free_strgs(char **strgs)
{
	int	j;

	j = 0;
	while (strgs[j])
	{
		free(strgs[j]);
		j++;
	}
	free(strgs);
}
