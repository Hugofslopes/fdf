/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2024/12/23 15:40:52 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	creat_map(char *av, int **array)
{
	char	**strgs;
	char	***strgs2;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strgs = ft_calloc(sizeof(char **), 1);
	fd = open(av, O_RDONLY);	
	while (get_next_line(fd))
		i++;
	close(fd);
	i--;
	fd = open(av, O_RDONLY);
	while (i >= 0)
	{
		strgs[j] = get_next_line(fd);
		printf("%s", strgs[j]);
		j++;
		i--;
	}
	close(fd);

	
	// free(strgs);

	// int j = 0;
	// while (--i >= 0)
	// {
	// 	while (strgs2[i][j])
	// 	{
	// 		ft_printf("%s\t", strgs2[i][j++]);
	// 	}
	// 	ft_printf("\n");
	// }
	
	// int h = 0;
	// int k = 0;
	// while(strgs[h])
	// {
	// 	k = 0;
	// 	while (strgs[h][k])
	// 	{
	// 		free(strgs[h][k]);
	// 		k++;
	// 	}
	// 	free (strgs[h]);
	// 	h++;
	// }
	// free(strgs);
}
