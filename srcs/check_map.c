/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:08:42 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/25 18:55:35 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
			return (1);
		}
	}
	else
	{
		free(str);
		return (1);
	}
	free(str);
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
