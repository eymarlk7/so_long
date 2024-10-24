/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcapalan <pcapalan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:25:15 by pcapalan          #+#    #+#             */
/*   Updated: 2024/10/24 20:28:38 by pcapalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

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
