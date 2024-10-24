/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:08:42 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/24 20:12:17 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	map_len_y(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	map_len_x(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int	find_char(char **map, char c)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	x = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_map_args(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'C'
				&& map[y][x] != 'E' && map[y][x] != 'P')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_walls2(char **map)
{
	int	y;
	int	x_len;

	y = 0;
	x_len = map_len_x(map[0]);
	while (map[y] != NULL)
	{
		if (map[y][0] != '1' || map[y][x_len - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

int	check_walls(char **map)
{
	int	x;
	int	y_len;

	x = 0;
	y_len = map_len_y(map);
	while (map[0][x])
	{
		if (map[0][x] != '1' || map[y_len - 1][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}
int	check_line(char **map)
{
	int	x_len;
	int	y;
	int	i;

	x_len = map_len_x(map[0]);
	y = 0;
	i = 0;
	while (map[y])
	{
		i = 0;
		while (map[y][i])
			i++;
		if (i != x_len)
			return (-1);
		y++;
	}
	return (0);
}

int	check_rectangle(char **map)
{
	int	y_len;
	int	x_len;

	y_len = map_len_y(map);
	x_len = map_len_x(map[0]);
	if (y_len == x_len)
		return (-1);
	return (0);
}

int	map_extension(char *map)
{
	size_t	map_size;
	char	*str;

	map_size = ft_strlen(map);
	str = ft_substr(map, map_size - 4, map_size - 1);
	if (map_size > 4)
	{
		if (ft_strcmp(str, ".ber") != 0)
		{
			free(str);
			return (-1);
		}
	}
	return (0);
}

int	ft_check_map(char *path, char **map)
{
	if (map_extension(path) != 0)
		return (1);
	else if (check_rectangle(map) != 0)
		return (2);
	else if ((check_line(map) != 0))
		return (3);
	else if (check_walls(map) != 0 && check_walls2(map) != 0)
		return (4);
	else if (check_map_args(map) != 0)
		return (5);
	else if (find_char(map, 'E') != 1 || find_char(map, 'P') != 1)
		return (6);
	else if (find_char(map, 'C') < 1)
		return (7);
	else if (check_path(map) == -1)
		return (8);
	return (0);
}

void	check_status(int nbr)
{
	if (nbr == 1)
		ft_printf("Error\nExtension of map invalid\n");
	else if (nbr == 2)
		ft_printf("Error\nThe map is not rectangular\n");
	else if (nbr == 3)
		ft_printf("Error\nThe map is not rectangular\n");
	else if (nbr == 4)
		ft_printf("Error\nThe map is not closed by walls\n");
	else if (nbr == 5)
		ft_printf("Error\nThere is an invalid character in the map\n");
	else if (nbr == 6)
		ft_printf("Error\nDon't have exit or player in the map\n");
	else if (nbr == 7)
		ft_printf("Error\nThere are no collectable on the map\n");
	else if (nbr == 8)
		ft_printf("Error\nFlood fill path invalid\n");
}
