void	creat_map_list(char ***strgs2, t_map **map)
{
	int			x;
	int			y;	

	y = 0;
	x = 0;
	while (y <= ((*map)->map_y) - 1)
	{
		while (strgs2[y][x])
		{
			if (strgs2[y][x] == NULL)
				break ;
			creat_map_list2(strgs2, map, y, x);
			x++;
		}
		if ((x - 1) != ((*map)->map_x))
			exit_from_atoi(strgs2, map, 2, &(*map)->node);
		y++;
		x = 0;
	}
	free_strgs2(strgs2);
}

long	ft_atoi_colors(t_map_node **new_node, char *str, char ***strgs2, \
t_map **map)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	//if (*str != '-' && *str != '+' && !(*str >= '0' && !*str <= '9') && *str != ' ')
		//exit_from_atoi(strgs2, map, 1, new_node);
	if (*str == ' ')
		while (*str == ' ')
			*str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str != '\0' && *str != ' ' && *str != ',' && *str && *str != '\n')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	if (*str == ',')
		get_hexa_color(new_node, str, strgs2, map);
	else if (*str != ' ' && *str != '\0' && *str != '\n')
		exit_from_atoi(strgs2, map, 1, new_node);
	else
		standard_color(new_node);
	return (sign * number);
}